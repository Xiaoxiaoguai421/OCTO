/*************************************************************************
    > File Name: SparseMatrix.h
    > Author:
    > Mail:
    > Created Time: 2017年11月07日 星期二 10时13分50秒
 ************************************************************************/

#ifndef _SPARSEMATRIX_H
#define _SPARSEMATRIX_H
#include<iostream>
#include<vector>
#include<cstdlib>
using namespace std;
template<class T>
struct Triple
{
	int r, c;
	T elem;
};
template<class T>
class SparseMatrix
{
public:
	SparseMatrix();
	SparseMatrix(Triple<T> *tlist, int rs, int cs, int n);
	void trans(SparseMatrix &B);
	SparseMatrix& plus(SparseMatrix &B);
	SparseMatrix& mult(SparseMatrix &B);
	void print();
private:
	vector< Triple<T> > triList;
	int rows, cols, num;
};
#endif
