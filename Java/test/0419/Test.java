/*************************************************************************
    > File Name: Test.java
    > Author: GZ
    > Mail: 194463810@qq.com
    > Created Time: 2018年04月19日 星期四 10时44分27秒
 ************************************************************************/
public class Test {

	public static void main(String[] args) {
		MyPoint p1 = new MyPoint(2, 3);
		MyPoint p2 = new MyPoint(4, 5);
		MyPoint p = new MyPoint();
		System.out.println("(2,3)到(4,5)的距离为: " + p.getD(p1, p2));
	}
}
