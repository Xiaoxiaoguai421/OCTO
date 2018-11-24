// test.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <windows.h>
#include "searchTree.h"
using namespace std;

int main()
{
	searchTree temp;
	_LARGE_INTEGER start;
	_LARGE_INTEGER end;
	double dq;
	LARGE_INTEGER f;
	QueryPerformanceFrequency(&f);
	dq = (double)f.QuadPart;	//计时器频率
	QueryPerformanceCounter(&start);
	temp.HEU();
//	temp.BFS();
//	temp.DFS();
	QueryPerformanceCounter(&end);
	cout<<"运行时间："<<2.2*(end.QuadPart-start.QuadPart)/dq <<"ns" <<endl;	//我的CPU频率2.2GHz
	cout << endl;
/*
	if (temp._REACH==true)
		temp.print_path();
*/
	return 0;
}