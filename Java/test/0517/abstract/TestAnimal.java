/********************************************************************************
    > File Name: TestAnimal.java
    > Author: GZ
    > Mail: 194463810@qq.com
    > Created Time: 2018年05月24日 星期四 11时08分32秒
********************************************************************************/

public class TestAnimal {

    public static void main(String[] args) {
        Animal bird = new Bird("麻雀", 2, 3);
        bird.showInfo();
        bird.move();
        bird.eat();
    }
}
