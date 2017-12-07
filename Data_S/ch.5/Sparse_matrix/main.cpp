/*************************************************************************
    > File Name: main.cpp
    > Author:
    > Mail:
    > Created Time: 2017年11月21日 星期二 20时23分40秒
 ************************************************************************/

#include<iostream>
#include"SparseMatrix.cpp"
#include<time.h>
using namespace std;
int main(void)
{
	int mR = 0, mC = 0, mN = 0;
	cout << "请输入矩阵的行列(i*j)\n$:";
	cin >> mR;
	cin.ignore();
	cin >> mC;
	vector<Triple<int> > tlist;
	cout << "请输入矩阵" << endl;
	for (int i = 0; i < mR; i++)
		for (int j = 0; j < mC; j++)
		{
			Triple<int> temp;
			cin >> temp.elem;
			if (temp.elem != 0)
			{
				temp.r = i;
				temp.c = j;
				tlist.push_back(temp);
				mN++;
			}
		}
	SparseMatrix<int> A(tlist, mR, mC, mN);
	clock_t start, end;
	SparseMatrix<int> C;
	start = clock();
	A.Trans(C);
	end = clock();
	cout << "转置后:" << endl;
	C.Print();
	cout << "用时" << (end - start) / CLOCKS_PER_SEC << "s" << endl;
//	cout<<"转置后的三元组:"<<endl;
//	C.Print_list();
	start = clock();
	A.Trans_F(C);
	end = clock();
	cout << "快速转置后：" << endl;
	C.Print();
	cout << "用时" << (end - start) / CLOCKS_PER_SEC << "s" << endl;
//矩阵相加
	tlist.clear();
	mN = 0;
	cout << "请输入被加矩阵" << endl;
	for (int i = 0; i < mR; i++)
		for (int j = 0; j < mC; j++)
		{
			Triple<int> temp;
			cin >> temp.elem;
			if (temp.elem != 0)
			{
				temp.r = i;
				temp.c = j;
				tlist.push_back(temp);
				mN++;
			}
		}
	SparseMatrix<int> B(tlist, mR, mC, mN);
//	cout << "被加矩阵的三元组" << endl;
//	B.Print_list();
	cout << "矩阵相加" << endl;
	A.Plus(B);
	A.Print();
//矩阵相乘
	tlist.clear();
	mR = mC = mN = 0;
	cout << "请输入相乘矩阵的行列(i*j)\n$:";
	cin >> mR;
	cin.ignore();
	cin >> mC;
	cout << "请输入被乘矩阵" << endl;
	for (int i = 0; i < mR; i++)
		for (int j = 0; j < mC; j++)
		{
			Triple<int> temp;
			cin >> temp.elem;
			if (temp.elem != 0)
			{
				temp.r = i;
				temp.c = j;
				tlist.push_back(temp);
				mN++;
			}
		}
	SparseMatrix<int> D(tlist, mR, mC, mN);
//	cout<<"相乘矩阵的三元组"<<endl;
//	D.Print_list();
	cout << "矩阵相乘" << endl;
	A.Mult(D);
	A.Print();
	return 0;
}
