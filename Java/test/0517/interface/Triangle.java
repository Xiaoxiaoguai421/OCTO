/********************************************************************************
    > File Name: Triangle.java
    > Author: GZ
    > Mail: 194463810@qq.com
    > Created Time: 2018年05月24日 星期四 10时33分08秒
********************************************************************************/
public class Triangle implements Shape {
    private double a, b, c;

    public Triangle(double a, double b, double c) {
        this.a = a;
        this.b = b;
        this.c = c;
    }
    public double area() {
        double p = (a + b + c) / 2;
        return Math.sqrt(p * (p - a) * (p - b) * (p - c));
    }
}
