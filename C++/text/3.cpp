//逆序输出 从键盘输入的三位数
#include<iostream>
using namespace std;
int main(void)
{
		int num;
		cout << "请输入一个三位数：" << endl;  // 这句可以不要
		cin >> num;
		int temp = num%10;   //除以10取的余数就是最右边的那个数字，例如123 取余得到最右边的3
		while(temp != 0)    
		{
				cout << temp;  // temp 里面放的是刚才取余得到的 3，直接输出它
				num /= 10;    //把123除以10一边去掉已经输出的数字，就是把123缩短成12
				temp = num%10; // 循环输出最右边的数字,知道输出完,123 -> 12 -> 12 -> 1->0不能再缩短了
		}
		cout << endl;   //这一句是为了美观
		return 0;
}
