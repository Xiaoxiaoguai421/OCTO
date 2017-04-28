//File  name : f0212.cpp
//Description: 析构函数实例
#include<iostream>
#include<cstring>
using namespace std;
class Person
{
		private:
				char* pName;
		public:
				Person(char* pN = "noName")   //构造函数，不具有任何类型，不返回任何值；Person是它的名字（和类名相同)
				{
						cout << "Construction " << pN <<endl;
						pName = new char[strlen(pN)+1];
						if(pName)
								strcpy(pName,pN);
				}
				~Person()   //析构函数,类名前加上～；不带参数，没有返回值
				{
						cout << "Destructing " << pName << endl;
						delete []pName;
				}
};
int main(void)
{
		Person p1("Randy");
}
