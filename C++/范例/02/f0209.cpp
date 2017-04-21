//利用参数初始化列表构造对象
#include<iostream>
using namespace std;
enum Month
{
		Jan=1,Feb,Mar,Apr,May,Jun,Aug,Sep,Oct,Nov,Dec     //依次赋值
};
class Date
{
		private:
				int year;
				Month month;
				int day;
		public:
				Date(int y=0,int m=0,int d=0):year(y),month(Month(m)),day(d)    //三种初始化形式
		{}
				Date(int d,Month m,int y):year(y),month(m),day(d)
		{}
				Date(Month m,int d,int y):year(y),month(m),day(d)
		{}
				bool isLeapYear()
				{
						if(year%400==0 || (year%100!=0 && year%4==0))
								return true;
						else
								return false;
				}
				void init_date(int y,int m,int d)
				{
						year = y;
						month = Month(m);
						day = d;
				}
				void print()
				{
						cout << year << "-" << month << "-" << day << endl;
				}
};
int main()
{
		Date today(Jan,28,2015);
		today.print();
		Date oneday(28,Feb,2015);
		oneday.print();
		Date tomorrow;
		if(today.isLeapYear())
				tomorrow.init_date(2015,2,29);
		else
				tomorrow.init_date(2015,3,1);
		tomorrow.print();
		return 0;
}
