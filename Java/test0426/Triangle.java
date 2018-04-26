/*************************************************************************
    > File Name: Triangle.java
    > Author: GZ
    > Mail: 194463810@qq.com
    > Created Time: 2018年04月26日 星期四 10时58分46秒
 ************************************************************************/
import java.util.Scanner;

public class Triangle {

	private double a;
	private double b;
	private double c;

	private double p;   //半周长
	private double s;

	public Triangle() {
		a = b = c = 0.0;
	}

	public Triangle(double a, double b, double c) {
		this.a = a;
		this.b = b;
		this.c = c;
	}


	public void getS() {
		if (a <= 0 || b <= 0 || c <= 0) {
			System.out.println("三角形边必须为正实数！");
			return;
		}
		if (isTriangle()) {
			p = (a + b + c) / 2;
			System.out.println("能构成三角形，且三角形面积为: " + Math.sqrt(p * (p - a) * (p - b) * (p - c)));
		} else {
			double min = (a > b) ? b : a;
			min = (min > c) ? c : min;
			p = (3 * min) / 2;
			System.out.println("不能构成三角形，以最短边构成的等边三角形面积为: " + Math.sqrt(p * (p - min) * (p - min) * (p - min)));
		}
	}

	public boolean isTriangle() {
		double max = 0;
		double mid = 0;
		double min = 0;
		max = (a > b) ? a : b;
		max = (max > c) ? max : c;
		if (max == a) {
			mid = (b > c) ? b : c;
			min = (b > c) ? c : b;
		} else if (max == b) {
			mid = (a > c) ? a : c;
			min = (a > c) ? c : a;
		} else if (max == c) {
			mid = (a > b) ? a : b;
			min = (a > b) ? b : a;
		}
		if ( (max < (mid + min)) && (min > (max - mid)) )
			return true;
		else
			return false;
	}

	public static void main(String[] ages) {
		double a, b, c;
		System.out.print("请输入三条边:");
		Scanner keyborad = new Scanner(System.in);
		a = keyborad.nextDouble();
		b = keyborad.nextDouble();
		c = keyborad.nextDouble();
		Triangle temp_triangle = new Triangle(a, b, c);
		temp_triangle.getS();
	}

}
