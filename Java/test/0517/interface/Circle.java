/********************************************************************************
    > File Name: Circle.java
    > Author: GZ
    > Mail: 194463810@qq.com
    > Created Time: 2018年05月24日 星期四 10时39分55秒
********************************************************************************/

public class Circle implements Shape {
    private double r;
    public Circle(double r) {
        this.r = r;
    }
    public double area() {
        return Math.PI * r * r;
    }
}
