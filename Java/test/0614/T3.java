/********************************************************************************
    > File Name: T3.java
    > Author: GZ
    > Mail: 194463810@qq.com
    > Created Time: 2018年06月27日 星期三 22时35分17秒
    >
    > 使用字符流方式，从键盘输入数据，输出到屏幕上
    >
********************************************************************************/

import java.io.FileOutputStream;

public class T3 {
    public static void main(String[] args) {
        try {
            byte[] b = new byte[512];
            System.out.print("键盘读入数据(字符流): ");
            int n = System.in.read(b);
            System.out.print("输出至屏幕(字符流): ");
            for (int i = 0; i < n; i++) {
                System.out.print((char)b[i]);
            }
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}
