/********************************************************************************
    > File Name: Bank.java
    > Author: GZ
    > Mail: 194463810@qq.com
    > Created Time: 2018年06月01日 星期五 08时42分13秒
********************************************************************************/

public class Bank {

    public static void main(String[] args) {
        Bank test = new Bank(100.0);
        System.out.println("显示余额：" + test.getbalawal());
        test.deposite(50.0);
        System.out.println("存50后，余额为：" + test.getbalawal());
        test.withdraw(50.0);
        System.out.println("取出50后，余额为：" + test.getbalawal());
    }

    private double balance;

    public Bank() {
        balance = 0;
    }

    public Bank(double b) {
        this.balance = b;
    }

    public void deposite(double balance) {
        this.balance += balance;
        System.out.println("存款成功!");
    }

    public void withdraw(double b)  {
        try {
            if (this.balance < b) {
                System.out.println("您的当前余额为：" + this.balance);
                throw new Exception("您的当前余额不足，请重新输入取款金额。");
            }
            this.balance -= b;
            System.out.println("取款成功。");
        } catch (Exception e) {
            System.out.println(e.getMessage());
        }
    }

    public double getbalawal() {
        return this.balance;
    }
}
