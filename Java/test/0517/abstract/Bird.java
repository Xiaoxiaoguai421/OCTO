/********************************************************************************
    > File Name: Bird.java
    > Author: GZ
    > Mail: 194463810@qq.com
    > Created Time: 2018年05月24日 星期四 10时59分13秒
********************************************************************************/

public class Bird extends Animal {

    public Bird(String name, int age, double weight) {
        this.name = name;
        this.age = age;
        this.weight = weight;
    }

    public void move() {
        System.out.println(name + "在天空飞。");
    }

    public void eat() {
        System.out.println(name + "吃虫子。");
    }

    public void showInfo() {
        System.out.println("鸟类名为：" + name + "，年龄为：" + age + "，重量为：" + weight);
    }
}
