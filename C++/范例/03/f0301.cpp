//File  name : f0301.cpp
//Description: 类对象的动态创建与释放
#include<iostream>
using namespace std;
enum Month
{
		Jan=1,Feb,Mar,Apr,May,Jun,Jul,Aug,Sep,Oct,Nov,Dec
};
class Date
{
		private:
				int year;
				Month month;
				int day;
		public:
				Date(int y=0,int m=0,int d=0):year(y),month(Month(m)),day(d)
		{
				cout << "in constructor1" << endl;
		}
				Date(int d,Month m,int y):year(y),month(m),day(d)
		{
				cout << "in constructor2" << endl;
		}
				Date(Month m,int d,int y):year(y),month(m),day(d)
		{
				cout << " in constructor3" << endl;
		}
				~Date()
				{
						cout << "in destructor" << endl;
				}
				bool isLeapYear()
				{
						if(year%400==0 || (year%4==0 && year%100 != 0))
										return true;
						else
										return false;
				}
				void init_date(int y,int m,int d)
				{
				       year = y;
				       month =Month(m);
				       day = d;
				}
				void print()
				{
				       cout << year << "-" << month << "-" << year << endl;
				}
};
int main(void)
{
		Date *pt1 =new Date(2016,1,1);
		pt1->print();  // 为什么pt1.print 和pt1->print不一样
		Date *pt2 =(Date*)malloc(sizeof(Date));
		pt2->print();
		pt2->init_date(2016,1,1);
		pt2->print();
		delete pt1;
		free(pt2);
}
