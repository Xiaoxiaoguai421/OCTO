/********************************************************************************
    > File Name: S2.java
    > Author: GZ
    > Mail: 194463810@qq.com
    > Created Time: 2018年06月27日 星期三 23时12分09秒
    >
    > 从键盘输入一行数据，输出到文件中
    >
********************************************************************************/

import java.io.*;

public class S2 {
    public static void main(String[] args) {
        try {
            BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
            BufferedWriter bw = new BufferedWriter(new FileWriter("S1.txt"));
            String strLine = br.readLine();
            bw.write(strLine);
            bw.flush();
            bw.close();
            br.close();
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}
