//常量成员的初始化
#include<iostream>
using namespace std;
class Circle
{
		private:
		double radius;
		const double PI;   //常变量
		public:
		Circle(double r,double pi):radius(r),PI(pi){}
		double getArea()
		{
				return PI*radius*radius;
		}
};
int main()
{
		Circle r1(1.1,3.14);
		cout << "the area is " << r1.getArea() << endl;
		Circle r2(1.1,3.141593);
		cout << "the area is " << r2.getArea() << endl;
		return 0;
}
