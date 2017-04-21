//File name   : f0104.cpp
//Dscription  : 类的构造函数
#include<iostream>
using namespace std;
class Date
{
		private:
				int year;
				int month;
				int day;
		public:
				Date()
				{
						cout << "进入构造函数" << endl;
				}
				void init_date(int y,int m,int d)
				{
						year = y;
						month = m;
						day = d;
				}
				bool isLeapYear()
				{
						if(year%400==0 || (year%4==0 && year%100 != 0))
								return true;
						else
								return false;
				}
				void print()
				{
						cout << year << "-" << month << "-" << day << endl;
				}
};
int main()
{
		Date days[3];
		for(int i=0;i<3;i++)
		{
				days[i].init_date(2017,4,i+1);
				days[i].print();
		}
		Date today;
		today.init_date(2017,2,28);
		today.print();
		return 0;
}
