/********************************************************************************
    > File Name: T5.java
    > Author: GZ
    > Mail: 194463810@qq.com
    > Created Time: 2018年06月27日 星期三 22时50分34秒
    >
    > 使用字符流方式，从文件读取数据，输出到文件中。
    >
********************************************************************************/

import java.io.*;

public class T5 {
    public static void main(String[] args) {
        try {
            FileReader  fr = new FileReader("T1.txt");
            FileWriter fw = new FileWriter("T2.txt");
            int n;
            while ((n = fr.read()) != -1) {
                fw.write((char)n);
            }
            fr.close();
            fw.close();
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}
