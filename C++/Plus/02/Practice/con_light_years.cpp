//File  name : con_light_years.cpp
//Description: convert light year into astronomical unit
//             1 light year = 63240 astronomical units
#include<iostream>
using namespace std;
int main(void)
{
		double ly,//light year
			   au;//astronomical unit
		cout << "Enter the number of light years: ";
		cin >> ly;
		au = 63240*ly;
		cout << ly << " light years = " << au << " astronomical units" << endl;
		return 0;
}
