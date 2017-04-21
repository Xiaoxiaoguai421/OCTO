//演示函数参数传递的传值形式中形参和实参的关系
//演示指针作为函数参数时形参与实参的关系
//演示引用作为函数参数时形参与实参的关系
#include<iostream>
using namespace std;
void my_swap1(int x,int y);   //函数声明
void my_swap2(int *px,int* py);
void my_swap3(int& x,int& y);
int main()
{
		int x,y;
		cout << "Please input two nambers:\n";
		cin >> x >> y;
		cout << "Before swapping\n";
		cout << "x =" << x <<",y= "<< y << endl;
		my_swap1(x,y);
		cout << "After swapping:\n";
		cout << "x=" << x <<",y=" << y << endl;
		my_swap2(&x,&y);
		cout << "x=" << x << ",y=" << y << endl;
		my_swap3(x,y);
		cout << "x=" << x << ",y=" << y << endl;
		return 0;
}
void my_swap1(int a,int b)
{
		int temp = a;
		a = b;
		b = temp;
}
void my_swap2(int* px,int*py)
{
		int temp = *px;
		*px = *py;
		*py = temp;
}
void my_swap3(int& x,int& y)
{
		int temp = x;
		x = y;
		y = temp;
}
