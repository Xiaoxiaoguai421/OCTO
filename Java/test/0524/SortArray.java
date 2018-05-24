/********************************************************************************
    > File Name: SortArray.java
    > Author: GZ
    > Mail: 194463810@qq.com
    > Created Time: 2018年05月24日 星期四 23时33分04秒
********************************************************************************/
import java.util.*;

public class SortArray {

    public static void main(String[] args) {
        int[] s = new int[] {20, 10, 50, 40, 30, 70, 60, 80, 90, 100};
        int[] buffer = new int[s.length];
        System.arraycopy(s, 0, buffer, 0, s.length);
        Arrays.sort(buffer);
        int i = 0, j = 0;
        for (i = buffer.length - 1, j = 0; i >= 0; i--, j++)
            s[j] = buffer[i];
        for (i = 0; i < s.length; i++)
            System.out.print(s[i] + " ");
        System.out.println();
    }
}


/*
//自定义比较器,在sort()中不能用
class ComparatorMe implements Comparator {
    public int compare(Object arg0, Object arg1) {
        int a = (int)arg0;
        int b = (int)arg1;
        return (a < b ? 1 : -1);
    }
}
*/
