/*************************************************************************
    > File Name: BiTree.h
    > Author:
    > Mail:
    > Created Time: 2017年11月14日 星期二 09时41分15秒
 ************************************************************************/

#ifndef _BITREE_H
#define _BITREE_H
#include<iostream>
#include<vector>
#include<stack>
#include<queue>
using namespace std;
template<class T>
struct BiNode
{
	T data;
	BiNode<T> *lchild;
	BiNode<T> *rchild;
};
template<class T>
class BiTree
{
public:
	BiTree();
	BiTree(vector<T> &pre);
	BiTree(vector<T> &pre, vector<T> &mid);
	BiTree(BiNode<T> &tree);
	~BiTree();

	void PreOrder();
	void InOrder();
	void PostOrder();
	void LevelOrder();
	void PreOrder_I();
	void PreOrder_II();
	void InOrder_I();

	int Count();
	int Height();
	BiNode<T>* Search(T e);
	BiNode<T>* SearchParent(BiNode<T> *child);
	void Print(BiNode<T> *q);
private:
	BiNode<T> *root;
	BiNode<T>* CreateByPre(vector<T> &pre, int &i);
	BiNode<T>* CreateByPreMid(vector<T> &pre, vector<T> &mid, int ipre, int imid, int n);
	BiNode<T>* Copy(BiNode<T> *p);
	void Free(BiNode<T> *p);
//遍历以p为根的二叉树
	void PreOrder(BiNode<T> *p);
	void InOrder(BiNode<T> *p);
	void PostOrder(BiNode<T> *p);
	void LevelOrder(BiNode<T> *p);
	void PreOrder_I(BiNode<T> *p);
	void VisitAlongLeft(BiNode<T> *p, stack<BiNode<T> *> &S);
	void PreOrder_II(BiNode<T> *p);
    void GoAlongLeft(BiNode<T> *p, stack<BiNode<T> *> &S);
	void InOrder_I(BiNode<T> *p);
//其他操作
	int Count(BiNode<T> *p);
	int Height(BiNode<T> *p);
	BiNode<T>* Search(BiNode<T> *p, T e);
	BiNode<T>* SearchParent(BiNode<T> *p, BiNode<T> *child);
};
#endif
