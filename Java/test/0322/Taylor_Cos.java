/*************************************************************************
	> File Name: Taylor_Cos.java
	> Author: GZ
	> Mail: 194463810@qq.com
	> Created Time: 2018年03月25日 星期日 19时28分02秒
 ************************************************************************/
import java.util.Scanner;
public class Taylor_Cos{
	public static double Taylor(double x){
		long fac=1;
		double n=1;
		double y=1;
		double sum=1;
		for(int i=2;Math.abs(y)>=1e-6;i+=2)
		{
			n=n*(-1);
			for(int j=1;j<=i;j++)
				fac=fac*j;
			y=Math.pow(x,i)*n/fac;
			sum+=y;
			fac=1;
		}
		return sum;
	}

	public static void main(String[] srgs){
		System.out.print("请输入x:");
		Scanner in=new Scanner(System.in);
		double x=in.nextDouble();
		System.out.println("Cos("+x+")="+Taylor(x));
	}
}
