/*************************************************************************
	> File Name: Selection.java
	> Author: GZ
	> Mail: 194463810@qq.com
	> Created Time: 2018年03月15日 星期四 10时58分16秒
 ************************************************************************/
public class Selection{

	public static double Select_If(double t){
		if(t>=0.0&&t<1.0)
			return t*t-1.0;
		else if(t>=1.0&&t<3.0)
			return t*t-2*t-2.0;
		else if(t>=3.0&&t<5.0)
			return t*t-t*Math.sin(t);
		else if(t>=5.0&&t<7.0)
			return t+1.0;
		else
			return t-1.0;
	}

	public static double Select_Switch(double t){

		switch( )
		{
			case 0:

				break;
			default:
				return t-1;
				break;
		}
	}

	public static void main(String[] args){
		double t=1.0;
		double result_if=Select_If(t);
		System.out.println("使用if-else:"+result_if);
		double result_Switch=Select_Switch(t);
		System.out.println("使用switch-case:"+result_Switch);
	}
}
