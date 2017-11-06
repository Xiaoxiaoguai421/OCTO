/*************************************************************************
    > File Name: Pscal_t.cpp
    > Author:
    > Mail:
    > Created Time: 2017年11月04日 星期六 15时58分13秒
 ************************************************************************/

#include<iostream>
#include<iomanip>
using namespace std;
int Pscal_t(int row, int col);
int main(void)
{
	int Row = 0, Col = 0;
	int Max_Row = 0;
	cout << "请输入要输出杨辉三角的行数\n$:";
	cin >> Max_Row;

	cout << Max_Row << "行杨辉三角如下" << endl;
	for (Row = 0; Row < Max_Row; Row++)
	{
		for (Col = 0; Col < Row; Col++)
			cout << Pscal_t(Row, Col) << setw(4);
		cout << Pscal_t(Row, Col);
		cout << endl;
	}
	return 0;
}

int Pscal_t(int row, int col)
{
	if ((col == 0) || (row == col))
		return 1;
	else
		return (Pscal_t(row - 1, col - 1) + Pscal_t(row - 1, col));
}
