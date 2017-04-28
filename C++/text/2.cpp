#include<iostream>
using namespace std;
int main(void)
{
		int a,b;  //这是两杯水
		cin >> a >> b; // 程序到这一步时会让你输入两个数
		int temp;  //这是第三个空瓶子，只是个工具
		//注意了啊，要交换了
		temp = a;
		a = b;
		b= temp;
		cout << a << " " << b << endl;
		return 0;
}
