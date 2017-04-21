#include<iostream>
#include<fstream>
#include<string>
#include<sstream>
using namespace std;
int main(void)
{
		string str_arry[100];
		string str;
		int count;
		ifstream in("date");
		if(!in)
		{
				cout << "Cant't open the file" << endl;
		}
		count = 0;
		while(getline(in,str))
		{
				istringstream sin(str);
	      		while(sin >> str_arry[count])
				{
						count++;
						if(count > 100)
								break;
				}
				if(count > 100)
						break;
		}
		for(int i = 0;i<count;i++)
		{
				cout << str_arry[i] << " ";
		}
		cout << endl;
		return 0;
}
