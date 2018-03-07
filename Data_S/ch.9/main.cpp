/*************************************************************************
    > File Name: main.cpp
    > Author:
    > Mail:
    > Created Time: 2018年01月17日 星期三 21时00分13秒
 ************************************************************************/

#include"BiSortTree.cpp"
const int MaxSize = 50;
int main(void)
{
	int a[MaxSize];
	int num;
	cout << "请输入待输入数据的个数\n$：";
	cin >> num;
	cout << "请输入数据\n$: ";
	for (int i = 0; i < num; i++)
		cin >> a[i];
	BiSortTree A(a, num);
	A.MidOrder();
	cout << "\n请输入新增数据\n$: ";
	int temp;
	cin >> temp;
	A.Insert(temp);
	cout << "插入新增数据后:";
	A.MidOrder();
	cout << "\n请输入要删除的数据\n$:";
	cin >> temp;
	if (A.Search(temp) && A.Search2(temp))
		A.Delete(temp);
	cout << "删除后:";
	A.MidOrder();
	cout << endl;
	return 0;
}
