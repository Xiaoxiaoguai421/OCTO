/*************************************************************************
	> File Name: Count_Prime.java
	> Author: GZ
	> Mail: 194463810@qq.com
	> Created Time: 2018年03月15日 星期四 10时36分24秒
 ************************************************************************/
public class Count_Prime{
	public static boolean IsPrime(int n){
		int i=2;
		while(i<n-1)
		{
			if(n%i==0)
				return false;
			i++;
		}
		return true;
	}
	public static void main(String[] args){
		int count=0;
		for(int num=100;num<=200;num++)
		{
			if(IsPrime(num))
			{
				if(count<9){
					System.out.print(num+" ");
					count++;
				}
				else{
					System.out.println(num);
					count=0;
				}
			}
		}
	}
}
