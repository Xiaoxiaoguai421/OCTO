/*************************************************************************
    > File Name: main.cpp
    > Author:
    > Mail:
    > Created Time: 2017年12月25日 星期一 23时00分12秒
 ************************************************************************/

#include"BiTree.cpp"
#include<string>
int main(void)
{
	vector<char> pre;
	vector<char> mid;
	string str;
	cout << "请输入先序序列\n&:";
	cin >> str;
	const char *pstr = str.c_str();
	for (int i = 0; i < str.length(); i++)
		pre.push_back(pstr[i]);
	cout << "请输入中序序列\n$:";
	cin >> str;
	pstr = str.c_str();
	for (int i = 0; i < str.length(); i++)
		mid.push_back(pstr[i]);
	BiTree<char> A(pre, mid);
	cout << "先序遍历：";
	A.PreOrder();
	cout << endl;
	cout << "中序遍历: ";
	A.InOrder();
	cout << endl;
	cout << "后序遍历：";
	A.PostOrder();
	cout << endl;
	cout << "层次遍历: ";
	A.LevelOrder();
	cout << endl;

//	cout<<"先序遍历(迭代I)：";A.PreOrder_I();cout<<endl;
	cout << "先序遍历(迭代II)：";
	A.PreOrder_II();
	cout << endl;
	cout << "中序遍历(迭代): ";
	A.InOrder_I();
	cout << endl;

	int cnt = A.Count();
	cout << "该二叉树有" << cnt << "个节点" << endl;
	cout << "该二叉树的高度为" << A.Height() << endl;
	char se_temp;
	cout << "请输入要查找的值\n$:";
	cin >> se_temp;
	BiNode<char> *child = A.Search(se_temp);
	BiNode<char> *parent = A.SearchParent(child);
	cout << se_temp << "父节点是";
	A.Print(parent);
	cout << endl;

	return 0;
}
