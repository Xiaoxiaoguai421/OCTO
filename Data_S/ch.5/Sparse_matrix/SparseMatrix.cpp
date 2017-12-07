/*************************************************************************
    > File Name: SparseMatrix.cpp
    > Author:
    > Mail:
    > Created Time: 2017年11月07日 星期二 10时31分30秒
 ************************************************************************/

#include"SparseMatrix.h"
template<class T>
SparseMatrix<T>::SparseMatrix()
{
	rows = cols = num = 0;
}

template<class T>
SparseMatrix<T>::SparseMatrix(vector<Triple<T> >tlist, int rs, int cs, int n)
{
	rows = rs;
	cols = cs;
	num = n;
	triList.resize(num);
	for (int i = 0; i < n; i++)
		triList[i] = tlist[i];
}

template<class T>
void SparseMatrix<T>::Trans(SparseMatrix &B)
{
	B.rows = cols;
	B.cols = rows;
	B.num = num;
	B.triList.resize(num);
	if (num == 0)
		return;
	int col = 0, p = 0, q = 0;
	for (col = 0; col < cols; col++)
		for (p = 0; p < num; p++)
			if (triList[p].c == col) //找列为col的三元组，交换行号
			{
				B.triList[q].r = triList[p].c;
				B.triList[q].c = triList[p].r;
				B.triList[q].elem = triList[p].elem;
				++q;
			}
}

template<class T>
void SparseMatrix<T>::Trans_F(SparseMatrix &B)
{
	B.rows = cols;
	B.cols = rows;
	B.num = num;
	B.triList.resize(num);
	if (num == 0)
		return;
	int *cnum = new int[cols];
	int *cpot = new int[cols];
	int col;
	for (col = 0; col < cols; col++)
		cnum[col] = 0;
	for (int t = 0; t < num; t++)
		++cnum[triList[t].c];
	cpot[0] = 0;
	for (col = 1; col < cols; col++)
		cpot[col] = cpot[col - 1] + cnum[col - 1];
	int q;
	for (int p = 0; p < num; p++)
	{
		col = triList[p].c;
		q = cpot[col];
		B.triList[q].r = triList[p].c;
		B.triList[q].c = triList[p].r;
		B.triList[q].elem = triList[p].elem;
		cpot[col]++;
	}
	delete[] cnum;
	delete[] cpot;
}

template<class T>
bool operator<(Triple<T> &t1, Triple<T> &t2)
{
	if (t1.r < t2.r)
		return true;
	else if (t1.r == t2.r && t1.c < t2.c)
		return true;
	else
		return false;
}

template<class T>
void SparseMatrix<T>::Plus(SparseMatrix& B)
{
	if (rows != B.rows && cols != B.cols)
	{
		cerr << "矩阵相加非法" << endl;
		exit(1);
	}
	int i = 0, j = 0;
	while (i < num && j < B.num)
	{
		if (triList[i].r == B.triList[j].r)
		{
			if (triList[i].c == B.triList[j].c) //相同位置的相加
				triList[i].elem += B.triList[j++].elem;
			else if (triList[i].c > B.triList[j].c) //B.triList[j]位置在triList[i]前面，直接填入
				triList.push_back(B.triList[j++]);
			else if (triList[i].c < B.triList[j].c)
				i++;
		}
		else if (triList[i].r > B.triList[j].r)
			triList.push_back(B.triList[j++]);
		else if (triList[i].r < B.triList[j].r)
			i++;
	}
	while (j < B.num)
		triList.push_back(B.triList[j++]);
	sort(triList.begin(), triList.end());   //三元组排序Print
	num = triList.size();
}

template<class T>
void SparseMatrix<T>::Mult(SparseMatrix& B)
{
	if (cols != B.rows)
	{
		cerr << "矩阵相乘非法" << endl;
		exit(1);
	}
	vector<Triple<T> >reList;
	Triple<T> temp;
	for (int i = 0; i < num; i++)
		for (int j = 0; j < B.num; j++)
			if (triList[i].c == B.triList[j].r)
			{
				temp.elem = triList[i].elem * B.triList[j].elem;
				temp.r = triList[i].r;
				temp.c = B.triList[j].c;
				reList.push_back(temp);
			}
	//相同位置的elem相加
	sort(reList.begin(), reList.end());
	int k = 0;
	triList.clear();
	triList.push_back(reList[0]);
	for (int i = 1; i < reList.size(); i++)
	{
		if (triList[k].r == reList[i].r && triList[k].c == reList[i].c)
			triList[k].elem += reList[i].elem;
		else
		{
			triList.push_back(reList[i]);
			k++;
		}
	}
	cols = B.cols;
	num = triList.size();
}

template<class T>
void SparseMatrix<T>::Print()
{
	int i = 0;
	cout << setw(5);
	for (int row = 0; row < rows; row++)
	{
		for (int col = 0; col < cols; col++)
		{
			if (triList[i].r == row && triList[i].c == col)
				cout << triList[i++].elem << setw(5);
			else
				cout << "0" << setw(5);
		}
		cout << endl;
	}
}

template<class T>
void SparseMatrix<T>::Print_list()
{
	for (int i = 0; i < num; i++)
		cout << triList[i].r << setw(5) << triList[i].c << setw(5) << setw(5) << triList[i].elem << endl;
}
