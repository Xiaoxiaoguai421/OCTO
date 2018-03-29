/*************************************************************************
	> File Name: Perfect_num.java
	> Author: GZ
	> Mail: 194463810@qq.com
	> Created Time: 2018年03月25日 星期日 19时56分37秒
 ************************************************************************/
public class Perfect_num{

	public static boolean isPerfect(int x){
		int sum=0;
		for(int i=1;i<x;i++)
		{
			if(x%i==0)
				sum+=i;
		}
		if(sum==x)	return true;
		else	return false;
	}

	public static void main(String[] args){
		int cnt=0;
		for(int i=1;i<=1000;i++)
		{
			if(isPerfect(i)){
				cnt++;
				if(cnt%9==0)
				{
					System.out.println(i);
					cnt=0;
				}
				else	System.out.print(i+" ");
			}
		}
	}
}
