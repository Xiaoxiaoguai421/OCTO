/********************************************************************************
    > File Name: T1.java
    > Author: GZ
    > Mail: 194463810@qq.com
    > Created Time: 2018年06月27日 星期三 22时16分29秒
    >
    > 使用字节流方式，从键盘输入数据，输出到文件中
    >
********************************************************************************/

import java.io.FileOutputStream;

public class T1 {
    public static void main(String[] args) {
        try {
            FileOutputStream fos = new FileOutputStream("T1.txt");
            byte[] b = new byte[512];
            System.in.read(b);
            fos.write(b);
            fos.close();
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}
