//File name    : f0114.cpp
//Description  : 演示文件以及输入输出的基本操作
#include<iostream>
#include<fstream>
#include<iomanip>
using namespace std;
int main(void)
{
		ifstream fin("date",ios_base::in);  //打开输入文件
		//判断文件是否打开成功
		if(!fin)
		{
				cout << "Can't open the file!" << endl;
				exit(0);
		}
		ofstream fout("result",ios_base::out); //打开输出文件
		//判断输出文件是否打开成功
		if(!fout)
		{
				cout << "Can't open the file!" << endl;
				exit(0);
		}
		//读取数据
		int i_arry[100];
		int count=0;
		while(fin >> i_arry[count])
		{
				count++;
				if(count>=100)
						break;
		}
		//输出到屏幕和文件上
		for(int i = 0;i < count;i++)
		{
				cout << setw(5) << i_arry[i]; //输出到屏幕上
				if((i+1) % 8 == 0)
						cout <<"\n";
				fout << setw(5) << i_arry[i];//输出到文件中
				if((i+1)%8==0)
						cout << "\n";
		}
		return 0;
}

