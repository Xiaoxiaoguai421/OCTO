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
enum BiThrNodeType{LINK,THREAD};
template<class T>
struct BiThrNode{
	BiThrNodeType ltype,rtype;
	T data;
	BiThrNode<T> *lchild,rchild;
};
template<class T>
class InBiThrTree
{
	public:
		InBiThrTree(){root=NULL;}
		InBiThrTree(vector<T> &pre);
	private:
		BiThrNode<T> *root;
};
#endif
