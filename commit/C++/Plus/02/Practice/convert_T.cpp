//File  name : convert_T.cpp
//Description: convert Celsius(C) into Fahrenheit(F)
//             F= 1.8*C + 32.0
#include<iostream>
using namespace std;
int main(void)
{
		float C,F;
		cout << "Please enter a Celsius value: " << endl;
		cin >> C;
		F = 1.8*C + 32.0;
		cout << C << " degree Celsius is " << F << " degree Fahrenheit" << endl;
		return 0;
}
