/*************************************************************************
    > File Name: InBiThrTree.h
    > Author:
    > Mail:
    > Created Time: 2017年12月28日 星期四 16时22分25秒
 ************************************************************************/

#ifndef _INBITHRTREE_H
#define _INBITHRTREE_H
#include<iostream>
#include<vector>
using namespace std;
enum BiThrNodeType {LINK, THREAD};
template<class T>
struct BiThrNode
{
	BiThrNodeType ltype, rtype;
	T data;
	BiThrNode<T> *lchild, *rchild;
};

template<class T>
class InBiThrTree
{
public:
	BiThrNode<T> *prenode = NULL;
	InBiThrTree()
	{
		root = NULL;
	}
	InBiThrTree(vector<T> &pre);
	void InThreaded();
	~InBiThrTree();
	void Search(T &item);
	BiThrNode<T>* GetNext(BiThrNode<T> *p);
	BiThrNode<T>* GetPrev(BiThrNode<T> *p);
	void Travese();
	BiThrNode<T>* GetParent(BiThrNode<T> *p);
private:
	BiThrNode<T> *root;
	BiThrNode<T>* CreateByPre(vector<T> &pre, int &i);
	void InThreaded(BiThrNode<T>* &p);  //改变BiThrNode<T>*p的值，引用参数p
	void Free(BiThrNode<T> *p);
};
#endif
