/********************************************************************************
    > File Name: S4.java
    > Author: GZ
    > Mail: 194463810@qq.com
    > Created Time: 2018年06月27日 星期三 23时27分50秒
    >
    > 从文件按行读取，输出到文件中
    >
********************************************************************************/

import java.io.*;

public class S4 {
    public static void main(String[] args) {
        try {
            BufferedReader br = new BufferedReader(new FileReader("S1.txt"));
            BufferedWriter bw = new BufferedWriter(new FileWriter("S4.txt"));
            while (br.ready()) {
                bw.write(br.readLine());
                bw.newLine();
            }
            bw.flush();
            bw.close();
            br.close();
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}
