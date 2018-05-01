/*************************************************************************
	> File Name: K_Merge.cpp
	> Author: GZ
	> Mail: 194463810@qq.com
	> Created Time: 2018年04月03日 星期二 16时58分10秒
 ************************************************************************/

#include<iostream>
#include<vector>
#include<queue>
using namespace std;
void Merge(vector<int> a,vector<int> b);
void K_Merge(vector<vector<int> > s,int k);
int main(void)
{

	return 0;
}

void K_Merge(vector<vector<int> > s,int k)
{

}

void Merge(vector<int> a,vector<int> b)
{
	queue<int> buffer;
	int len_a=a.size();
	inr len_b=b.size();
	while(len_a>=0&&len_b>=0)
	{
		if(a[len_a]>=b[len_b])	buffer.push_back(b[len_b--]);
		else	buffer.push_back(a[len_a--]);
	}
	while(len_a>=0)
		buffer.push_back(a[len_a--]);
	while(len_b>=0)
		buffer,push_back(b[len_b]);
}
