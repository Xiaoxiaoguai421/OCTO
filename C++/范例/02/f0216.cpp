//File  name : f0216.cpp
//Description: 浅复制存在的问题,如对一个地址连续进行两次free
#include<iostream>
#include<cstring>
using namespace std;
class CName
{
		private:
				char* strName;  //字符指针
		public:
				CName()
				{
						strName = NULL;  //空值
						cout << "in constructor" << endl;
				}
				CName(char* str)
				{
						strName = new char[strlen(str)+1];
						strcpy(strName,str);  //复制内容
						cout << "in constructor" << endl;
				}
				CName(const CName &one)   //深复制
				{
						strName = new char[strlen(one.strName)+1];
						strcpy(strName,one.strName); //复制内容
						cout << "in deepen copy constructor" << endl;
				}
				~CName()
				{
						if(strName)
								delete []strName;
						strName = NULL;
						cout << "in destructor" << endl;
				}
				char* getName()
				{
						return strName;
				}
				void setName(char* str)
				{
						if(strName)
								delete []strName;
						strName = new char[strlen(str)+1];
						strcpy(strName,str); //copy date
				}
};
void print(CName one)
{
		cout << one.getName() << endl;
}
int main(void)
{
		CName person1("virgil");
		CName person2(person1);  //using copy constructoer ,why not light copy constructor??
		print(person1);
		print(person2);
		return 0;
}
