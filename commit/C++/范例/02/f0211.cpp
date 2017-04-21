//File name  : f0211.cpp
//Description: 引用的初始化
#include<iostream>
using namespace std;
class A
{
		private:
				int i;
				int &ri;
				int &rii;
		public:
				A(int ii):i(ii),ri(i),rii(ii)     //这一行是什么鬼
		{
				cout << "in constructor\n" << "i= " << i <<" ri= " << ri << " rii= " << rii << endl;
		}
				void print()
				{
						cout << "i= " << i << " ri= " << ri <<" rii= " << rii << endl;
				}

};
int main(void)
{
		A a(2);
		a.print();
		return 0;
}
