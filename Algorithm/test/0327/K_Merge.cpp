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
	queue<int> buffer1;
	queue<int> buffer2;
	for(int i=0;i<a.size();i++)
		buffer1.push_back(a[i]);
	for(int i=0;i<b.size();i++)
		buffer2.push_back(b[i]);
	while()
}
