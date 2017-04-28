//演示默认参数值和重载函数的使用
#include<iostream>
#include<iomanip>
using namespace std;
int sum_arry(int arry[],int count)
{
		int sum = 0;
		for(int i=0;i<count;i++)
				sum += arry[i];
		return sum;
}
void print(int arry[],int count,bool flag = true) //最好还是用两个重载函数，符合逻辑性且便于维护
{
		if(flag)
		{
				for(int i=0;i<count;i++)
						cout << setw(5) << arry[i];    //setw()设置输出间隔
		}
		else
		{
				cout << setw(10) << sum_arry(arry,count);
		}
}
int main(void)
{
		int arry[] = {1,2,3,4,5,6,7,8,9};
		int count = 9;
		if(sum_arry(arry,count)>10)
				print(arry,count);
		else
				print(arry,count,false);
		return 0;
}
