//File  name : deliver.cpp
//Descriptiom: using functon to add hours and minutes
#include<iostream>
using namespace std;
void fun(int h,int m);
int main(void)
{
		int h, //hour
			m; //minute
		cout <<"Enter the number of hours: " ;
		cin >> h;
		cout <<"Enter the number of minutes: ";
		cin >> m;
		fun(h,m);
		return 0;
}
void fun(int h,int m)
{
		cout <<"Time: "<< h <<":"<< m <<endl;
}
