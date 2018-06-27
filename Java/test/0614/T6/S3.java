/********************************************************************************
    > File Name: S3.java
    > Author: GZ
    > Mail: 194463810@qq.com
    > Created Time: 2018年06月27日 星期三 23时21分53秒
    >
    > 从文件按行读取，输出到屏幕上
    >
********************************************************************************/

import java.io.*;

public class S3 {
    public static void main(String[] args) {
        try {
            BufferedReader br = new BufferedReader(new FileReader("S1.txt"));
            while (br.ready()) {
                System.out.println(br.readLine());
            }
            br.close();
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}
