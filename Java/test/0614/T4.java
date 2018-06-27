/********************************************************************************
    > File Name: T4.java
    > Author: GZ
    > Mail: 194463810@qq.com
    > Created Time: 2018年06月27日 星期三 22时45分08秒
    >
    > 使用字符流方式，从文件读取数据，输出到屏幕上。
    >
********************************************************************************/

import java.io.FileReader;

public class T4 {
    public static void main(String[] args) {
        try {
            FileReader fr = new FileReader("T1.txt");
            int n;
            while ((n = fr.read()) != -1) {
                System.out.print((char)n);
            }
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}
