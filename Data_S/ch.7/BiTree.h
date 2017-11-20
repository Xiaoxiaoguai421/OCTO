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
using namespace std;
template<class T>
struct BiNode
{
	T data;
	BiNode<T> *parent;
	BiNode<T> *lchild;
	BiNode<T> *rchild;
};
template<class T>
class T
{
public:
	BiTree();
	BiTree(vector<T> &pre);
	BiTree(vector<T> &pre, vector<T> &mid);
	BiTree(BiTree<T> &tree);
	~BiTree();

	void PreOrder();
	void InOrder();
	void PostOrder();
	void LevelOrder();

	int Count();
	int Height();
	BiNode<T>* Search(T e);
	BiNode<T>* SearchParent(T e);
private:
	BiNode<T> *root;
	BiNode<T>* CreateByPre(vector<T> &pre, int &i);
	void PreOrder(BiTree<T> *p);
	void InOrder(BiTree<T> *p);
	void PostOrder(BiTree<T> *p);
	void LevelOrder(BiTree<T> *p);
};
#endif
