/********************************************************************************
    > File Name: Animal.java
    > Author: GZ
    > Mail: 194463810@qq.com
    > Created Time: 2018年05月24日 星期四 10时55分06秒
********************************************************************************/

public abstract class Animal {
    public String name;
    public int age;
    public double weight;

    public void showInfo() {
        System.out.println("name: " + name + ",age: " + age + ",weight: " + weight);
    }
    abstract public void move();
    abstract public void eat();
}
