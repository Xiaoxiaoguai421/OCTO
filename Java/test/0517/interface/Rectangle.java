/********************************************************************************
    > File Name: Rectangle.java
    > Author: GZ
    > Mail: 194463810@qq.com
    > Created Time: 2018年05月24日 星期四 10时42分20秒
********************************************************************************/

public class Rectangle implements Shape {
    private double width, length;

    public Rectangle(double w, double l) {
        this.width = w;
        this.length = l;
    }
    public double area() {
        return width * length;
    }
}
