/*************************************************************************
    > File Name: TestRectangle.java
    > Author: GZ
    > Mail: 194463810@qq.com
    > Created Time: 2018年04月12日 星期四 10时56分08秒
 ************************************************************************/
import java.util.Scanner;

public class TestRectangle {

	public static void main(String[] args) {
		int length = 0;
		int height = 0;
		Scanner keyboard = new Scanner(System.in);
		System.out.println("请输入矩形的长、宽（0~50的整数）：");
		length = keyboard.nextInt();
		height = keyboard.nextInt();

		Rectangle example = new Rectangle();
		example.set_length(length);
		example.set_height(height);
		System.out.println("矩形面积：" + example.getArea());
		System.out.println("矩形周长: " + example.getPerimeter());
		System.out.println("打印矩形");
		example.draw();
	}
}
