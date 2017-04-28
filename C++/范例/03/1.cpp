#include<iostream>
#include<string.h>
using namespace std;
int main(void)
{
		int a = 4;
		char* p = "I am a stdent";
		cout << strlen(a) << endl;
		cout << strlen(&a) << endl;
		cout << strlen(p) << endl;
		return 0;
}
