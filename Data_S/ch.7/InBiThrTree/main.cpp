/*************************************************************************
    > File Name: main.cpp
    > Author:
    > Mail:
    > Created Time: 2018年01月04日 星期四 16时09分55秒
 ************************************************************************/

#include"InBiThrTree.cpp"
#include<string>
#include<cstring>
int main(void)
{
	string str;
	cout << "请输入二叉树先序序列\n$:";
	cin >> str;
	vector<char> pre;
	char *p = new char[str.length()];
	strcpy(p, str.data());
	for (int i = 0; i < str.length(); i++)
		pre.push_back(p[i]);
	delete p;
	InBiThrTree<char> A(pre);
	A.InThreaded();
	cout << "中序遍历:";
	A.Travese();
	char item;
	cout << "\n请输入待查询元素\n$:";
	cin >> item;
	A.Search(item);
	return 0;
}
