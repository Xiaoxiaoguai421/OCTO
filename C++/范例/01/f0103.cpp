//函数调用的基本过程
#include<iostream>
using namespace std;
int max(int x,int y)
{
		return (x > y ? x : y);
}
int main()
{
		int x,y,z;
		cout << "Please input 3 numbers:\n";
		cin >> x >> y >> z;
		cout <<"the max value:"<< max(x,max(y,z)) << endl;
		return 0;
}
