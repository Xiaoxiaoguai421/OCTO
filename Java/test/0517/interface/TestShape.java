/********************************************************************************
    > File Name: TestShape.java
    > Author: GZ
    > Mail: 194463810@qq.com
    > Created Time: 2018年05月24日 星期四 10时44分18秒
********************************************************************************/

public class TestShape {

    public static void main(String[] args) {
        Shape s[] = new Shape[3];
        s[0] = new Triangle(3, 4, 5);
        s[1] = new Circle(1.0);
        s[2] = new Rectangle(1.0, 2.0);
        for (int  i = 0; i < s.length; i++)
            System.out.println(s[i].area());
    }
}
