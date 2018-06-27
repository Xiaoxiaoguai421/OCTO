/********************************************************************************
    > File Name: Test.java
    > Author: GZ
    > Mail: 194463810@qq.com
    > Created Time: 2018年06月07日 星期四 09时27分24秒
********************************************************************************/

import java.io.*;

public class Test {
    public static void main(String[] args) {

        try {
            FileReader fr = new FileReader("data.txt");
            BufferedReader br = new BufferedReader(fr);
            FileWriter fw = new FileWriter("target.txt");
            BufferedWriter bw = new BufferedWriter(fw);
            String strLine;
            while (br.ready()) {
                strLine = br.readLine();
                bw.write(strLine);
                bw.newLine();
                System.out.println(strLine);
            }
            bw.flush(); //刷新缓冲，将流输出到目的
            bw.close();
            br.close();
            fw.close();
            fr.close();
        } catch (IOException e) {
            e.printStackTrace();
        }


        /*
        char[] c = new char[512];
        byte[] b = new byte[512];
        try {
            int n = System.in.read(b);

            //字节数组转String
            String temp = new String(b);
            System.out.println(temp);

            //字节转字符
            for (int i = 0; i < n; i++)
                System.out.print((char)b[i]);
            System.out.println();

        } catch (IOException ie) {
            System.out.println("haha");
        } catch (Exception e) {
            System.out.println("hahaha");
        }
        */

        /*键盘整行读取
        try {
            BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
            String str;
            str = br.readLine();
            System.out.println("String：" + str);
        } catch (Exception e) {
            System.out.println("hahahahaha");
        }
        */
    }
}
