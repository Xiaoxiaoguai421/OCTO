/*************************************************************************
	> File Name: QuickSort.cpp
	> Author: GZ
	> Mail: 194463810@qq.com
	> Created Time: 2018年03月13日 星期二 19时02分36秒
 ************************************************************************/

#include<iostream>
#include<time.h>
#include<stdlib.h>
using namespace std;
const int MaxSize=10;
int Partition_1(int r[],int i,int j);
int Partition_2(int r[],int i,int j);
void QuickSort_1(int r[],int i,int j);
int main(void)
{
	int r1[MaxSize];
	int r2[MaxSize];
	srand(time(NULL));
	for(int i=0;i<MaxSize;i++)
		r1[i]=r2[i]=rand();
	QuickSort_1(r1,0,MaxSize-1);
	for(int i=0;i<MaxSize;i++)
		cout<<r1[i]<<'\t';
	cout<<endl;
	return 0;
}

int Partition_1(int r[],int i,int j)
{
	int temp=r[i];
	while(i<j)
	{
		while(i<j&&r[j]>=temp)
			j--;
		if(i<j)
			r[i++]=r[j];
		while(i<j&&r[i]<=temp)
			i++;
		if(i<j)
			r[j--]=r[i];
	}
	r[i]=temp;
	return i;
}

void QuickSort_1(int r[],int i,int j)
{
	if(i<j)
	{
		int pivot=Partition_1(r,i,j);
		QuickSort_1(r,i,pivot-1);
		QuickSort_1(r,pivot+1,j);
	}
}
