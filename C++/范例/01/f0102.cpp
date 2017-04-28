//演示string类的基本使用方法
#include<iostream>
#include<string>
using namespace std;
int main()
{
		string ls_str1;
		string ls_str2 = "ABCDEFGH";
		string ls_str3 = "acdefgh";

		ls_str1 = ls_str2;   //赋值操作
		cout << ls_str1 << endl;
		ls_str1.swap(ls_str3);    //交换字符
		cout << ls_str1 << endl;
		cout << ls_str3 << endl;
		ls_str1 +='A';  //添加字符
		cout << ls_str1 << endl;
		ls_str1.insert(1,"B");  //插入字符串
		cout << ls_str1 << endl;
		ls_str1.erase(5,2);   //删除字符
		cout << ls_str1 << endl;
		cout << ls_str1 + ls_str3 << endl;   //字符串链接
		//比较
		if(ls_str1 > ls_str3)
		{
				cout << "ls_str1 > ls_str3 \n";
		}
		else if(ls_str1 == ls_str3)
		{
				cout << "ls_str1 and ls_str3 are equal.\n";
		}
		else
		{
				cout << "ls_str1 <ls_str3\n";
		}
		//存取、下标和at()函数
		ls_str1[4] = 'F';
		cout << ls_str1 << endl;
		for(unsigned int i = 0; i < ls_str1.length(); i++)
		{
				ls_str1[i] += 1;  //所有字母的ASCII值加1
		}
		cout << ls_str1 << endl;
		cout << ls_str1.at(4) << endl;
		ls_str1.at(4) = 'H';
		cout << ls_str1 << endl;

		string ls_str4 = "0123456789";
		cout << ls_str4 << endl;
		ls_str1 += ls_str4.substr(1,4);   //提取字串
		cout << ls_str1 << endl;

		ls_str1.clear();    //移除字符串
		if(ls_str1.empty())
		{
				cout << "ls_str1 is cleared!" << endl;
		}
		return 0;
}
