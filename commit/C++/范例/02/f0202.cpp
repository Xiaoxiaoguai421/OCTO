//函数参数的传递方式
#include<iostream>
using namespace std;
struct Date
{
		int year;
		int month;
		int day;
};
void init_date1(Date date,int year,int month,int day)
{
		date.year = year;
		date.month = month;
		date.day = day;
}
void init_date2(Date* pdate,int year,int month,int day)
{
		pdate->year = year;
		pdate->month = month;
		pdate->day = day;
}
void init_date3(Date& date,int year,int month,int day)
{
		date.year = year;
		date.month = month;
		date.day = day;
}
void print(Date& date)
{
		cout << date.year << "-" << date.month << "-" << date.day << endl;
}
int main()
{
		Date today,yesterday,tomorrow;
		init_date1(today,2105,2,28);
		print(today);
		init_date2(&yesterday,2015,2,27);
		print(yesterday);
		init_date3(tomorrow,2015,3,1);
		print(tomorrow);
		return 0;
}
