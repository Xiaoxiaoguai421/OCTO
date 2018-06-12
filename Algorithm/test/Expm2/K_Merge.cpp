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

void K_Merge(vector<vector<int> > s,int low,int high)
{
    int middle;
    if(low<high)
    {
        middle=(low+high)/2;
        K_Merge(s,low,middle);
        K_Merge(s,middle+1,high);
        Merge(s,low,middle,high);
    }
}

//s[low]~s[high]
//vector<vector<int> >逻辑上相连，空间、时间开销都大
void Merge(vector<vector<int> >s,int low,int middle,int high)
{
    int len_1=(middle-low+1)*k;
    int len_2=(high-middle)*k;
	vector<int> buffer_1(len_1);
    vector<int> buffer_2(len_2);

}
