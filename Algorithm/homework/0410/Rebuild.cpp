/*************************************************************************
    > File Name: Rebuild.cpp
    > Author: GZ
    > Mail: 194463810@qq.com
    > Created Time: 2018年04月17日 星期二 00时01分56秒
 ************************************************************************/

#include<set>
#include<iostream>
#include<string>
#include<vector>
using namespace std;
/*
 * word does not name a type
//建立词典
set<string> word;
word.insert("it");
word.insert("was");
word.insert("the");
word.insert("best");
word.insert("of");
word.insert("times");
*/
bool dict(string w, set<string> word);
void Rebuild(string str, set<string> word);
int main(void)
{
	//建立词典
	set<string> word;
	word.insert("it");
	word.insert("was");
	word.insert("the");
	word.insert("best");
	word.insert("of");
	word.insert("times");

	string str = " itwasthebestoftimes";
	Rebuild(str, word);

	return 0;
}

void Rebuild(string str, set<string> word)
{
	vector<bool> v(str.length());
	v[0] = true;
	vector<int> index(str.length());
	index[0] = -1;

	for (int i = 1; i <= str.length() - 1; i++)
		for (int j = i - 1; j >= 0; j--)
		{
			string temp = str.substr(j + 1, i - j);
			if (v[j] && dict(temp, word))
			{
				v[i] = true;
				index[i] = j + 1;
				break;
			}
			else
			{
				v[i] = false;
				index[i] = -1;
			}
		}
	if (v[str.length() - 1])
	{
		string str_s = "";
		int end = str.length() - 1;
		int begin = index[end];
		while (begin != -1)
		{
			str_s = str.substr(begin, end - begin + 1) + " " + str_s;
			end = begin - 1;
			begin = index[end];
		}
		cout << "Rebuild:" << str_s << endl;
	}
	else
		cout << "Rebuild failed!" << endl;
}

bool dict(string w, set<string> word)
{
	if (word.count(w) == 1)
		return true;
	else    return false;
}
