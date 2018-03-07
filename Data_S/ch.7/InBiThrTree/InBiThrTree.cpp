/*************************************************************************
    > File Name: InBiThrTree.cpp
    > Author:
    > Mail:
    > Created Time: 2018年01月02日 星期二 09时55分24秒
 ************************************************************************/

#include"InBiThrTree.h"
template<class T>
BiThrNode<T>* InBiThrTree<T>::CreateByPre(vector<T> &pre, int &i)
{
	T e = pre[i++];
	if (e == '*')
		return NULL;
	BiThrNode<T> *p = new BiThrNode<T>;
	p->data = e;
	p->ltype = LINK;
	p->rtype = LINK;
	p->lchild = CreateByPre(pre, i);
	p->rchild = CreateByPre(pre, i);
	return p;
}
template<class T>
InBiThrTree<T>::InBiThrTree(vector<T> &pre)
{
	int i = 0;
	root = CreateByPre(pre, i);
}

template<class T>
void InBiThrTree<T>::InThreaded(BiThrNode<T>* &p)
{
	if (p == NULL)
		return;
	InThreaded(p->lchild);
	if (p->lchild == NULL)
	{
		p->ltype = THREAD;
		p->lchild = prenode;
	}
	if (p->rchild == NULL)
		p->rtype = THREAD;
	if (prenode != NULL)
	{
		if (prenode->rtype == THREAD)
			prenode->rchild = p;
	}
	prenode = p;
	InThreaded(p->rchild);
}
template<class T>
void InBiThrTree<T>::InThreaded()
{
	InThreaded(root);
}

template<class T>
void InBiThrTree<T>::Free(BiThrNode<T> *p)
{
	if (p == NULL)
		return;
	Free(p->lchild);
	Free(p->rchild);
	delete p;
	p = NULL;
}
template<class T>
InBiThrTree<T>::~InBiThrTree()
{
	Free(root);
}

template<class T>
void InBiThrTree<T>::Search(T &item)
{
	BiThrNode<T> *p = root;
	while (p->ltype == LINK)
		p = p->lchild;
	while (p != NULL)
	{
		if (p->data == item)
			break;
		p = GetNext(p);
	}
	if (p != NULL)
	{
		BiThrNode<T> *_prev = GetPrev(p);
		cout << item << "的前驱为：" << _prev->data << endl;
		BiThrNode<T> *_next = GetNext(p);
		cout << item << "的后继为：" << _next->data << endl;
		BiThrNode<T> *_parent = GetParent(p);
		cout << item << "的父节点为：" << _parent->data << endl;
	}
}

template<class T>
BiThrNode<T>* InBiThrTree<T>::GetNext(BiThrNode<T> *p)
{
	if (p->rtype == THREAD)
		return p->rchild;
	p = p->rchild;
	while (p->ltype == LINK)
		p = p->lchild;
	return p;
}

template<class T>
BiThrNode<T>* InBiThrTree<T>::GetPrev(BiThrNode<T> *p)
{
	if (p->ltype == THREAD)
		return p->lchild;
	p = p->lchild;
	while (p->rtype == LINK)
		p = p->rchild;
	return p;
}

template<class T>
void InBiThrTree<T>::Travese()
{
	BiThrNode<T> *p = root;
	while (p->ltype == LINK)
		p = p->lchild;
	while (p != NULL)
	{
		cout << p->data << " ";
		p = GetNext(p);
	}
}
template<class T>
BiThrNode<T>* InBiThrTree<T>::GetParent(BiThrNode<T> *p)
{
	if (p == NULL)
		return NULL;
	BiThrNode<T> *parent;
	parent = p;
	while (parent->rtype == LINK)
		parent = parent->rchild;
	parent = parent->rchild;
	if (parent && parent->lchild == p)
		return parent;
	parent = p;
	while (parent->ltype == LINK)
		parent = parent->lchild;
	parent = parent->lchild;
	return parent;
}
