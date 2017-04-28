#include<iostream>
using namespace std;
int main(void)
{
		char a,b;
		cout << "请输入两个大写字母" << endl;
		cin >> a >> b;
		a = a + 32;
		b= b + 32;
		cout << "他们的小写字母是: " << a << " " << b << endl;
		return 0;
}
