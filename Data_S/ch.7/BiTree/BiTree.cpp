/*************************************************************************
    > File Name: BiTree.cpp
    > Author:
    > Mail:
    > Created Time: 2017年11月14日 星期二 09时49分53秒
 ************************************************************************/

#include"BiTree.h"

/*      构造、析构     */
template<class T>
BiTree<T>::BiTree()
{
	root = NULL;
}
//由带空指针标记的先序序列构造二叉树
template<class T>
BiNode<T>* BiTree<T>::CreateByPre(vector<T> &pre, int &i)
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
//先序+中序构造
template<class T>
BiNode<T>* BiTree<T>::CreateByPreMid(vector<T> &pre, vector<T> &mid, int ipre, int imid, int n)
{
	if (n == 0)
		return NULL;
	BiNode<T> *p = new BiNode<T>;
	p->data = pre[ipre];
	int i = 0;
	for (i = 0; i < n; i++)
		if (pre[ipre] == mid[imid + i])
			break;
	p->lchild = CreateByPreMid(pre, mid, ipre + 1, imid, i);
	p->rchild = CreateByPreMid(pre, mid, ipre + i + 1, imid + i + 1, n - i - 1);
	return p;
}
template<class T>
BiTree<T>::BiTree(vector<T> &pre, vector<T> &mid)
{
	int n = pre.size();
	root = CreateByPreMid(pre, mid, 0, 0, n);
}
//拷贝构造函数
template<class T>
BiNode<T>* BiTree<T>::Copy(BiNode<T> *p)
{
	if (p == NULL)
		return NULL;
	BiNode<T> *newp = new BiNode<T>;
	newp->data = p->data;
	newp->lchild = Copy(p->lchild);
	newp->rchild = Copy(p->rchild);
	return newp;
}
template<class T>
BiTree<T>::BiTree(BiNode<T> &tree)
{
	root = Copy(tree.root);
}
//析构
template<class T>
void BiTree<T>::Free(BiNode<T> *p)
{
	if (p == NULL)
		return;
	Free(p->lchild);
	Free(p->rchild);
	delete p;
}
template<class T>
BiTree<T>::~BiTree()
{
	Free(root);
}

/*      遍历      */
//   V|L|R(recur)
template<class T>
void BiTree<T>::PreOrder(BiNode<T> *p)
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
//   L|V|R(recur)
template<class T>
void BiTree<T>::InOrder(BiNode<T> *p)
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
//   L|R|V(recur)
template<class T>
void BiTree<T>::PostOrder(BiNode<T> *p)
{
	if (p == NULL)
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
//  层次遍历(recur)
template<class T>
void BiTree<T>::LevelOrder()
{
	if (root == NULL)
		return;
	queue<BiNode<T>* > Q;
	Q.push(root);
	while (!Q.empty())
	{
		BiNode<T> *p = Q.front();
		Q.pop();
		cout << p->data;
		if (p->lchild != NULL)
			Q.push(p->lchild);
		if (p->rchild != NULL)
			Q.push(p->rchild);
	}
}

//   L|V|R(iterate)
template<class T>
void BiTree<T>::PreOrder_I(BiNode<T> *p)
{
	stack<BiNode<T> *> S;
	if (p != NULL)
		S.push(p);  //根节点入栈
	while (!S.empty())
	{
		p = S.top();
		S.pop();
		cout << p->data;
		if (p->rchild != NULL)
			S.push(p->rchild);  //右子树先进后出
		if (p->rchild != NULL)
			S.push(p->lchild);
	}
}
template<class T>
void BiTree<T>::PreOrder_I()
{
	PreOrder_I(root);
}
//   V|L|R(iterate)
template<class T>
void BiTree<T>::VisitAlongLeft(BiNode<T> *p, stack<BiNode<T> *> &S)
{
	while (p)
	{
		cout << p->data;
		S.push(p->rchild);
		p = p->lchild;
	}
}
template<class T>
void BiTree<T>::PreOrder_II(BiNode<T> *p)
{
	stack<BiNode<T> *> S;   //辅助栈
	while (true)
	{
		VisitAlongLeft(p, S);   //左侧树
		if (S.empty())
			break;
		p = S.top();
		S.pop();
	}
}
template<class T>
void BiTree<T>::PreOrder_II()
{
	PreOrder_II(root);
}
//  L|V|R(iterate)
template<class T>
void BiTree<T>::GoAlongLeft(BiNode<T> *p, stack<BiNode<T> *> &S)
{
	while (p)
	{
		S.push(p);
		p = p->lchild;
	}
}
template<class T>
void BiTree<T>::InOrder_I(BiNode<T> *p)
{
	stack<BiNode<T> *> S;
	while (true)
	{
		GoAlongLeft(p, S);
		if (S.empty())
			break;
		p = S.top();
		S.pop();
		cout << p->data;
		p = p->rchild;
	}
}
template<class T>
void BiTree<T>::InOrder_I()
{
	InOrder_I(root);
}
/*      其他操作        */
//   统计结点数
template<class T>
int BiTree<T>::Count(BiNode<T> *p)
{
	if (p == NULL)
		return 0;
	int left = Count(p->lchild);
	int right = Count(p->rchild);
	return (1 + left + right); // 1-->统计了当前结点
}
template<class T>
int BiTree<T>::Count()
{
	return Count(root);
}
//   求二叉树的高度
template<class T>
int BiTree<T>::Height(BiNode<T> *p)
{
	if (p == NULL)
		return 0;
	int left = Height(p->lchild);
	int right = Height(p->rchild);
	if (left > right)
		return left + 1;
	else
		return right + 1;
}
template<class T>
int BiTree<T>::Height()
{
	return Height(root);
}
//   查找
template<class T>
BiNode<T>* BiTree<T>::Search(BiNode<T> *p, T e)
{
	if (p == NULL)
		return NULL;
	if (p->data == e)
		return p;
	BiNode<T> *q = Search(p->lchild, e);
	if (q != NULL)
		return q;
	return Search(p->rchild, e);
}
template<class T>
BiNode<T>* BiTree<T>::Search(T e)
{
	return Search(root, e);
}
//   查找父节点
template<class T>
BiNode<T>* BiTree<T>::SearchParent(BiNode<T> *p, BiNode<T> *child)
{
	if (p == NULL || child == NULL)
		return NULL;
	if (p->lchild == child || p->rchild == child)
		return p;
	BiNode<T> *q = SearchParent(p->lchild, child);
	if (q != NULL)
		return q;
	return SearchParent(p->rchild, child);
}
template<class T>
BiNode<T>* BiTree<T>::SearchParent(BiNode<T> *child)
{
	return SearchParent(root, child);
}

template<class T>
void BiTree<T>::Print(BiNode<T> *q)
{
	cout << q->data;
}
