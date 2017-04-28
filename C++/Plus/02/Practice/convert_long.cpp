//File  name: convert_long.cpp
//Descripton: converting long into yard (1 long = 220 yard)
#include<iostream>
using namespace std;
int main(void)
{
		int dist;  //save date
		cout << "Please enter a distance in long: " << endl;
		cin >> dist;
	//	dist = 220*dist;
		cout << "The distance is " << 220* dist << " yard" << endl;
		return 0;
}
