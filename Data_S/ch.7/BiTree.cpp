/*************************************************************************
    > File Name: BiTree.cpp
    > Author:
    > Mail:
    > Created Time: 2017年11月14日 星期二 09时49分53秒
 ************************************************************************/

#include"BiTree.h"
template<class T>
BiTree<T>::BiTree()
{
	root = NULL;
}

//由带空指针标记的先序序列构造二叉树
template<class T>
BiNode<T>* BiTree<T>::CreateByPre(BiNode<T> &pre, int &i)
{
	T e = pre[i++];
	if (e == '*')
		return NULL;
	BiNode<T> *p = new BiNode<T>;
	p->data = e;
	p->lchild = CreateByPre(pre, i);
	p->rchild = CreateByPre(pre, i);
	return p;
}
template<class T>
BiTree<T>::BiTree(vector<T> &pre)
{
	int i = 0;
	root = CreatByPre(pre, i);
}

//先序遍历
template<class T>
void BiTree<T>::PreOrder(BiTree<T> *p)
{
	if (p == NULL)
		return;
	cout << p->data;
	PreOrder(p->lchild);
	PreOrder(p->rchild);
}
template<class T>
void BiTree<T>::PreOrder()
{
	PreOrder(root);
}

//中序遍历
template<class T>
void BiTree<T>::InOrder(BiTree<T> *p)
{
	if (p == NULL)
		return;
	InOrder(p->lchild);
	cout << p->data;
	InOrder(p->rchild);
}
template<class T>
void BiTree<T>::InOrder()
{
	InOrder(root);
}

//后序遍历
template<class T>
void BiTree<T>::PostOrder(BiTree<T> *p)
{
	if (p = NULL)
		return;
	PostOrder(p->lchild);
	PostOrder(p->rchild);
	cout << p->data;
}
template<class T>
void BiTree<T>::PostOrder()
{
	PostOrder(root);
}

//层级遍历
template<class T>
void BiTree<T>::LeveOrder()
{
	if (root == NULL)
		return;
	SeqQueue<BiNode<T>* > Q;
	Q.EnQueue(root);
	while (!Q.isEmpty())
	{
		BiNode<T> *p = Q.DeQueue();
		cout << p->data;
		if (p->lchild != NULL)
			Q.EnQueue(p->lchild);
		if (p->rchild != NULL)
			Q.EnQueue(p->rchild);
	}
}
