/*************************************************************************
    > File Name: CalculateE.java
    > Author: GZ
    > Mail: 194463810@qq.com
    > Created Time: 2018年03月29日 星期四 10时44分31秒
 ************************************************************************/
public class CalculateE {

	public static void main(String[] args) {
		double sum = 1;
		double fac = 1.0;
		int i;
		for (i = 1; Math.abs(1 / fac) >= 1e-4; i++) {
			fac = fac * i;
			sum += 1 / fac;
		}
		String result=String.format("%.4f",sum);
		System.out.println("e=1+1/1!+...+1/n!+..=" + result + " (精确到小数点后四位)");
	}

}
