/********************************************************************************
    > File Name: S1.java
    > Author: GZ
    > Mail: 194463810@qq.com
    > Created Time: 2018年06月27日 星期三 23时02分50秒
    >
    > 从键盘输入一行数据，输出到屏幕上。
    >
********************************************************************************/

import java.io.*;

public class S1 {
    public static void main(String[] args) {
        try {
            BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
            String strLine = br.readLine();
            System.out.println(strLine);
            br.close();
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}
