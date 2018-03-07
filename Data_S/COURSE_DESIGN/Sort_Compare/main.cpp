/*************************************************************************
    > File Name: main.cpp
    > Author:
    > Mail:
    > Created Time: 2018年02月27日 星期二 20时49分11秒
 ************************************************************************/

#include"Sort.h"
#include<time.h>
#include<iostream>
int main(void)
{
	fstream file_out("Data", ios::out);
	if (!file_out)
	{
		cerr << "打开文件失败！" << endl;
		exit(1);
	}
	int temp;
	srand((unsigned)time(0));
	for (int i = 0; i < MaxNum; i++)
		file_out << rand() << ' ';
	file_out.close();

	int source_1[MaxNum];
	int source_2[MaxNum];
	int source_3[MaxNum+1];
	int source_4[MaxNum];

	int cnt = 0;
	fstream file_in("Data", ios::in);
	if (!file_in)
	{
		cerr << "文件打开失败!";
		exit(1);
	}
	while (!file_in.eof())	//eof()在读取完最后一个时，仍然是FALSE；当再读取下一个（未成功时)，才变成TRUE
	{
		file_in >> temp;
		source_1[cnt] = temp;
		source_2[cnt] = temp;
		source_3[cnt+1] = temp;
		source_4[cnt] = temp;
		cnt++;
	}
	file_in.close();
	cout << "共有" << (cnt-1) << "个数据" << endl;

	clock_t start,end;
	start=clock();
	ShellSort(source_1,MaxNum);
	end=clock();
	fstream file_out_Shell("Data_Shell", ios::out);
	for(int i=0;i<MaxNum;i++)
		file_out_Shell<<source_1[i]<<" ";
	file_out_Shell.close();
	cout<<"ShellSort use:"<<(double)(end-start)/CLOCKS_PER_SEC<<"s"<<endl;

	start=clock();
	QuickSort(source_2,0,MaxNum-1);
	end=clock();
	fstream file_out_Quick("Data_Quick", ios::out);
	for(int i=0;i<MaxNum;i++)
		file_out_Quick<<source_2[i]<<" ";
	file_out_Shell.close();
	cout<<"QuickSort use:"<<(double)(end-start)/CLOCKS_PER_SEC<<"s"<<endl;

	start=clock();
	HeapSort(source_3,MaxNum);
	end=clock();
	fstream file_out_Heap("Data_Heap", ios::out);
	for(int i=1;i<MaxNum+1;i++)
		file_out_Heap<<source_3[i]<<" ";
	file_out_Heap.close();
	cout<<"HeapSort use:"<<(double)(end-start)/CLOCKS_PER_SEC<<"s"<<endl;

	start=clock();
	MergeSort(source_4,MaxNum);
	end=clock();
	fstream file_out_Merge("Data_Merge", ios::out);
	for(int i=0;i<MaxNum;i++)
		file_out_Merge<<source_4[i]<<" ";
	file_out_Merge.close();
	cout<<"MergeSort use:"<<(double)(end-start)/CLOCKS_PER_SEC<<"s"<<endl;

	return 0;
}
