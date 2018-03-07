/*************************************************************************
    > File Name: BiSortTree.h
    > Author:
    > Mail:
    > Created Time: 2018年01月17日 星期三 20时07分49秒
 ************************************************************************/

#ifndef _BISORTTREE_H
#define _BISORTTREE_H
#include<iostream>
using namespace std;
struct BiNode
{
	int key;
	BiNode *lchild, *rchild;
};
class BiSortTree
{
	BiNode *root;
	void Insert(BiNode *&ptr, int k);
	void MidOrder(BiNode *ptr); //中序遍历
	BiNode* Search(BiNode *ptr, int k);
	BiNode* Search2(BiNode *ptr, int k);
	void Delete(BiNode* &ptr, int k);
	void Free(BiNode* ptr);
public:
	BiSortTree(int a[], int n);
	~BiSortTree();
	void Insert(int k);
	void MidOrder();
	bool Search(int k);
	bool Search2(int k);
	void Delete(int k);
};
#endif
