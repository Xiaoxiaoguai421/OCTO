package com.example.zszx;

import com.hankcs.hanlp.HanLP;
import com.hankcs.hanlp.seg.Segment;
import com.hankcs.hanlp.seg.common.Term;
import org.apache.spark.SparkConf;
import org.apache.spark.api.java.JavaRDD;
import org.apache.spark.api.java.JavaSparkContext;
import org.apache.spark.mllib.classification.NaiveBayes;
import org.apache.spark.mllib.classification.NaiveBayesModel;
import org.apache.spark.mllib.linalg.Vector;
import org.apache.spark.mllib.linalg.Vectors;
import org.apache.spark.mllib.regression.LabeledPoint;

import java.io.*;
import java.util.*;

/*
  Spark贝叶斯分类器 + HanLP分词器 + 实现问题语句的抽象+模板匹配+关键性语句还原
 */
public class ModelProcess {

    // 分类标签号和问句模板对应表
    Map<Double, String> questionsPattern;

    //Spark贝叶斯分类器
    NaiveBayesModel nbModel;

    // 词语和下标的对应表   == 词汇表
    Map<String, Integer> vocabulary;

    //关键字与其词性的map键值对集合 == 句子抽象
    Map<String, String> abstractMap;

    //指定问题question及字典的txt模板所在的根目录
    String rootDirPath = "/home/gz_zhu/data/";  //data数据自定义,可放在指定路径(服务器??)

    // 分类模板索引
    int modelIndex = 0;

    public ModelProcess() throws Exception{
        questionsPattern = loadQuestionsPattern();
        vocabulary = loadVocabulary();
        nbModel = loadClassifierModel();
    }

    public ModelProcess(String rootDirPath) throws Exception{
        this.rootDirPath = rootDirPath+'/';
        questionsPattern = loadQuestionsPattern();
        vocabulary = loadVocabulary();
        nbModel = loadClassifierModel();
    }

    public ArrayList<String> analyQuery(String queryString) throws Exception{
        /**
         * 打印问句
         */
        System.out.println("原始句子："+queryString);
        System.out.println("========HanLP开始分词========");

        /**
         * 抽象句子，利用HanPL分词，将关键字进行词性抽象
         */
        String abstr = queryAbstract(queryString);
        System.out.println("句子抽象化结果："+abstr);// nm 的 导演 是 谁

        /**
         * 将抽象的句子与spark训练集中的模板进行匹配，拿到句子对应的模板
         */
        String strPatt = queryClassify(abstr);
        System.out.println("句子套用模板结果："+strPatt); // nm 制作 导演列表


        /**
         * 模板还原成句子，此时问题已转换为我们熟悉的操作
         */
        String finalPattern = queryExtenstion(strPatt);
        System.out.println("原始句子替换成系统可识别的结果："+finalPattern);// 但丁密码 制作 导演列表


        ArrayList<String> resultList = new ArrayList<String>();
        resultList.add(String.valueOf(modelIndex));
        String[] finalPattArray = finalPattern.split(" ");
        for (String word : finalPattArray)
            resultList.add(word);
        return resultList;
    }

    public  String queryAbstract(String querySentence){
        // 句子抽象化
        Segment segment = HanLP.newSegment().enableCustomDictionary(true);
        List<Term> terms = segment.seg(querySentence);
        String abstractQuery = "";
        abstractMap = new HashMap<String, String>();
        int nrCount = 0; //nr 人名词性这个 词语出现的频率
        for (Term term : terms) {
            String word = term.word;
            String termStr = term.toString();
            System.out.println(termStr);
            if (termStr.contains("yy")) {        //yy 年份
                abstractQuery += "yy ";
                abstractMap.put("yy", word);
            }else if (termStr.contains("zy")) {  //zy  专业
                abstractQuery += "zy ";
                abstractMap.put("zy", word);
            } else if (termStr.contains("zsjh")) { //zsjh 招生计划
                abstractQuery += "zsjh ";
                abstractMap.put("zsjh", word);
            } else if (termStr.contains("pro")) { //pro 省份
                abstractQuery += "pro ";
                abstractMap.put("pro", word);
            }
            else {
                abstractQuery += word + " ";
            }
        }
        System.out.println("========HanLP分词结束========");
        return abstractQuery;
    }

    public  String queryExtenstion(String queryPattern){
        // 句子还原
        Set<String> set = abstractMap.keySet();
        for (String key : set) {
            /**
             * 如果句子模板中含有抽象的词性
             */
            if (queryPattern.contains(key)) {

                /**
                 * 则替换抽象词性为具体的值
                 */
                String value = abstractMap.get(key);
                queryPattern = queryPattern.replace(key, value);
            }
        }
        String extendedQuery = queryPattern;
        /**
         * 当前句子处理完，抽象map清空释放空间并置空，等待下一个句子的处理
         */
        abstractMap.clear();
        abstractMap = null;
        return extendedQuery;
    }



    /**
     * 加载词汇表 == 关键特征 == 与HanLP分词后的单词进行匹配
     * @return
     */
    public  Map<String, Integer> loadVocabulary(){
        Map<String, Integer> vocabulary = new HashMap<String, Integer>();
        File file = new File(rootDirPath + "question/vocabulary.txt");
        BufferedReader br = null;
        try {
            br = new BufferedReader(new FileReader(file));
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        }
        String line;
        try {
            while ((line = br.readLine()) != null) {
                String[] tokens = line.split(":");
                int index = Integer.parseInt(tokens[0]);
                String word = tokens[1];
                vocabulary.put(word, index);
            }
        } catch (NumberFormatException e) {
            e.printStackTrace();
        } catch (IOException e) {
            e.printStackTrace();
        }
        return vocabulary;

    }

    /**
     * 加载文件，并读取内容返回
     * @param filename
     * @return
     * @throws IOException
     */
    public  String loadFile(String filename) throws IOException{
        File file = new File(rootDirPath + filename);
        BufferedReader br = new BufferedReader(new FileReader(file));
        String content = "";
        String line;
        while ((line = br.readLine()) != null) {
            /**
             * 文本的换行符暂定用"`"代替
             */
            content += line + "`";
        }
        /**
         * 关闭资源
         */
        br.close();
        return content;
    }

    /**
     * 句子分词后与词汇表进行key匹配转换为double向量数组
     * @param sentence
     * @return
     * @throws Exception
     */
    public  double[] sentenceToArrays(String sentence) throws Exception{
        double[] vector = new double[vocabulary.size()];
        /**
         * 模板对照词汇表的大小进行初始化，全部为0.0
         */
        for (int i = 0; i < vocabulary.size(); i++) {
            vector[i] = 0;
        }

        /**
         * HanLP分词，拿分词的结果和词汇表里面的关键特征进行匹配
         */
        Segment segment = HanLP.newSegment();
        List<Term> terms = segment.seg(sentence);
        for (Term term : terms) {
            String word = term.word;
            /**
             * 如果命中，0.0 改为 1.0
             */
            if (vocabulary.containsKey(word)) {
                int index = vocabulary.get(word);
                vector[index] = 1.0;
            }
        }
        return vector;
    }

    /**
     * Spark朴素贝叶斯(naiveBayes)
     * @return
     * @throws Exception
     */
    public  NaiveBayesModel loadClassifierModel() throws Exception{
        SparkConf conf = new SparkConf().setAppName("NaiveBayesTest").setMaster("local[*]");
        JavaSparkContext sc = new JavaSparkContext(conf);
        /**
         * 训练集生成
         * labeled point 是一个局部向量，要么是密集型的要么是稀疏型的
         * 用一个label/response进行关联。在MLlib里，labeled points 被用来监督学习算法
         * 我们使用一个double数来存储一个label，因此我们能够使用labeled points进行回归和分类
         */
        List<LabeledPoint> train_list = new LinkedList<LabeledPoint>();
        String[] sentences = null;
        /**
         * [0]某年省内专业的招生计划.txt
         */
        String zsjhQuestions = loadFile("question/[0]某年省内专业的招生计划.txt");
        sentences = zsjhQuestions.split("`");
        for (String sentence : sentences) {
            double[] array = sentenceToArrays(sentence);
            LabeledPoint train_one = new LabeledPoint(0.0, Vectors.dense(array));
            train_list.add(train_one);
        }
        /**
         * [1]某年某省的分数线.txt
         */
        String fsxQuestions = loadFile("question/[1]某年某省的分数线.txt");
        sentences = fsxQuestions.split("`");
        for (String sentence : sentences) {
            double[] array = sentenceToArrays(sentence);
            LabeledPoint train_one = new LabeledPoint(1.0, Vectors.dense(array));
            train_list.add(train_one);
        }
        /**
         * SPARK的核心是RDD(弹性分布式数据集)
         * Spark是Scala写的,JavaRDD就是Spark为Java写的一套API
         * JavaSparkContext sc = new JavaSparkContext(sparkConf);    //对应JavaRDD
         * SparkContext	    sc = new SparkContext(sparkConf)    ;    //对应RDD
         */
        JavaRDD<LabeledPoint> trainingRDD = sc.parallelize(train_list);
        NaiveBayesModel nb_model = NaiveBayes.train(trainingRDD.rdd());

        /**
         * 记得关闭资源
         */
        sc.close();

        /**
         * 返回贝叶斯分类器
         */
        return nb_model;
    }

    /**
     * 加载问题模板 == 分类器标签
     * @return
     */
    public  Map<Double, String> loadQuestionsPattern(){
        Map<Double, String> questionsPattern = new HashMap<Double, String>();
        File file = new File(rootDirPath + "/question/question_classification.txt");
        BufferedReader br = null;
        try {
            br = new BufferedReader(new FileReader(file));
        } catch (FileNotFoundException e1) {
            e1.printStackTrace();
        }
        String line;
        try {
            while ((line = br.readLine()) != null) {
                String[] tokens = line.split(":");
                double index = Double.valueOf(tokens[0]);
                String pattern = tokens[1];
                questionsPattern.put(index, pattern);
            }
        } catch (NumberFormatException e) {
            e.printStackTrace();
        } catch (IOException e) {
            e.printStackTrace();
        }
        return questionsPattern;
    }

    /**
     * 贝叶斯分类器分类的结果，拿到匹配的分类标签号，并根据标签号返回问题的模板
     * @param sentence
     * @return
     * @throws Exception
     */
    public  String queryClassify(String sentence) throws Exception{
        double[] testArray = sentenceToArrays(sentence);
        Vector v = Vectors.dense(testArray);

        /**
         * 对数据进行预测predict
         * 句子模板在 spark贝叶斯分类器中的索引【位置】
         * 根据词汇使用的频率推断出句子对应哪一个模板
         */
        double index = nbModel.predict(v);
        modelIndex = (int)index;
        System.out.println("the model index is " + index);
        return questionsPattern.get(index);
    }

    public static void main(String[] agrs) throws Exception {
        ModelProcess modleProcess=new ModelProcess();
        ArrayList<String> result=modleProcess.analyQuery("2016年江苏省的分数线是多少");
        System.out.println("ArrayList<String> result的大小: "+result.get(0)+" "+result.get(1)+" "+result.get(2)+" "+result.get(3));

        String province=result.get(2);
        System.out.println("处理前"+province);
        if(province.contains("省"))
            province=province.substring(0,province.length()-1);
        System.out.println("处理后"+province);
        System.out.println("测试Process!!");
    }

}
