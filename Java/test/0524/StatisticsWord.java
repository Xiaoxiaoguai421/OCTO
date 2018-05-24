/********************************************************************************
    > File Name: StatisticsWord.java
    > Author: GZ
    > Mail: 194463810@qq.com
    > Created Time: 2018年05月24日 星期四 20时32分48秒
********************************************************************************/

public class StatisticsWord {

    public static void main(String[] args) {
        String words = "wow hello world or nothing";
        int countStartsWith_w = 0;
        int countOR = 0;
        int countLength_3 = 0;

        String[] strs = words.split(" ");
        for (int i = 0; i < strs.length; i++) {
            if (strs[i].startsWith("w"))
                countStartsWith_w++;
            if (strs[i].equals("or"))
                countOR++;
            if (strs[i].length() == 3)
                countLength_3++;
        }
        System.out.println(words);
        System.out.println("有" + countStartsWith_w + "个单词以w开头");
        System.out.println("有" + countOR + "个or单词");
        System.out.println("有" + countLength_3 + "个长度为3的单词");

    }

}
