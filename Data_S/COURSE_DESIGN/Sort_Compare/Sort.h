/*************************************************************************
	> File Name: Sort.h
	> Author: 
	> Mail: 
	> Created Time: 2018年02月27日 星期二 20时06分45秒
 ************************************************************************/

#ifndef _SORT_H
#define _SORT_H
#include<iostream>
#include<stdio.h>
#include<cstdlib>
#include<fstream>
using namespace std;
const int MaxNum=25000;
void ShellSort(int r[],int n);

int Partition(int r[],int i,int j);
void QuickSort(int r[],int i,int j);

void Shif(int r[],int k,int m);
void HeapSort(int r[],int n);

void Merge(int r[],int r1[],int s,int m,int t);
void MergePass(int r[],int r1[],int n,int h);
void MergeSort(int r[],int n);
#endif
