/*************************************************************************
    > File Name: SparseMatrix.h
    > Author:
    > Mail:
    > Created Time: 2017年11月07日 星期二 10时13分50秒
 ************************************************************************/

#ifndef _SPARSEMATRIX_H
#define _SPARSEMATRIX_H
#include<iostream>
#include<iomanip>
#include<vector>
#include<cstdlib>
#include<algorithm>
#include<fstream>
using namespace std;
template<class T>
struct Triple
{
	int r, c;
	T elem;
};

template<class T>
bool operator<(Triple<T> &t1, Triple<T> &t2);

template<class T>
class SparseMatrix
{
public:
	SparseMatrix();
	SparseMatrix(vector<Triple<T> > tlist, int rs, int cs, int n);
	void Trans(SparseMatrix &B);
	void Trans_F(SparseMatrix &B);
	void Plus(SparseMatrix &B);
	void Mult(SparseMatrix &B);
	void Print();   //打印矩阵
	void Print_list();  //打印三元组
private:
	vector< Triple<T> > triList;
	int rows, cols, num;
};
#endif
