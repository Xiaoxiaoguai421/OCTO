//File  name : f0217.cpp
//Description: 对象的赋值
#include<iostream>
using namespace std;
class Box
{
		private:
				int heigth;
				int widgth;
				int length;
		public:
				Box(int h=10,int w=10,int len=10);  //声明有默认参数的构造函数
				int volume();
};
Box::Box(int h,int w,int len)
{
		heigth = h;
	    widgth = w;
		length = len;
}
int Box::volume()
{
		return  (heigth*widgth*length);  //返回体积
}

int main()
{
		Box box1(1,6,4),box2;   //定义两个对象box1,box2
		cout << "The volume of box1 is " << box1.volume() << endl;  //应该输出24
	    cout << "The volume of box2 is " << box2.volume() << endl;  
		box2 = box1;   //将box1的值赋给box2
		cout << "Look.The volume of box2 is " << box2.volume() << endl;  //应该输出24
		return 0;
}
