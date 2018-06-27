/********************************************************************************
    > File Name: T2.java
    > Author: GZ
    > Mail: 194463810@qq.com
    > Created Time: 2018年06月27日 星期三 22时26分31秒
    >
    > 使用字节流方式，从键盘输入数据，输出到屏幕上。
    >
********************************************************************************/

import java.io.FileOutputStream;

public class T2 {
    public static void main(String[] args) {
        try {
            byte[] b = new byte[512];
            System.out.print("输入: ");
            int n = System.in.read(b);
            System.out.print("输出到屏幕上：");
            for (int i = 0; i < n; i++) {
                System.out.print((char)b[i]);
            }
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}
