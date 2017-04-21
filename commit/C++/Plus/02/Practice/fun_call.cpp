//File  name : fun_calling.cpp
//Description: calling function
#include<iostream>
using namespace std;
void fun1();
void fun2();
int main(void)
{
		fun1();
		fun1();
		fun2();
		fun2();
		return 0;
}
void fun1()
{
		cout << "Three blind mice" << endl;
}
void fun2()
{
		cout << "See how they run" << endl;
}
