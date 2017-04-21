//提取运算符读取文本数据
#include<iostream>
#include<fstream>
#include<string>
using namespace std;
int main(void)
{
		string str_arry[100];
		int count;
		//定义输入流对象，并打开文件
		ifstream in("date");
		if(!in)
		{
				cout << "Can't open the file!" << endl;
		}
		//读取数据
		count = 0;
		while(in >> str_arry[count])  
		{
				count++;
				if(count > 100)
						break;
		}
		for(int i=0;i<count;i++)
				cout << str_arry[i] << " ";
		cout << endl;
		return 0;
}
