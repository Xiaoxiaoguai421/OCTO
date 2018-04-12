/*************************************************************************
    > File Name: Rectangle.java
    > Author: GZ
    > Mail: 194463810@qq.com
    > Created Time: 2018年04月12日 星期四 10时43分46秒
 ************************************************************************/
public class Rectangle {

	int length;
	int height;

	public void set_length(int l) {
		length = l;
	}

	public void set_height(int h) {
		this.height = h;
	}

	public int getArea() {
		return length * height;
	}

	public int getPerimeter() {
		return  2 * (length + height);
	}

	public void draw() {
		for (int i = 0; i < height; i++) {
			for (int j = 0; j < length; j++)
				System.out.print('*');
			System.out.println();
		}
	}
}
