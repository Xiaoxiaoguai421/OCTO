/*************************************************************************
    > File Name: BiSortTree.cpp
    > Author:
    > Mail:
    > Created Time: 2018年01月17日 星期三 20时12分46秒
 ************************************************************************/
#include"BiSortTree.h"
void BiSortTree::Insert(BiNode* &ptr, int k)
{
	if (ptr == NULL)
	{
		ptr = new BiNode;
		ptr->key = k;
		ptr->lchild = ptr->rchild = NULL;
	}
	else
	{
		if (k < ptr->key)
			Insert(ptr->lchild, k);
		else if (k > ptr->key)
			Insert(ptr->rchild, k);
	}
}
void BiSortTree::Insert(int k)
{
	Insert(root, k);
}

BiSortTree::BiSortTree(int a[], int n)
{
	root = NULL;
	for (int i = 0; i < n; i++)
		Insert(root, a[i]);
}

void BiSortTree::Free(BiNode *ptr)
{
	if (ptr == NULL)
		return;
	Free(ptr->lchild);
	Free(ptr->rchild);
	delete ptr;
}
BiSortTree::~BiSortTree()
{
	Free(root);
}

BiNode* BiSortTree::Search(BiNode *ptr, int k)
{
	if (ptr == NULL)
		return NULL;
	else
	{
		if (ptr->key == k)
			return ptr;
		else if (ptr->key > k)
			return Search(ptr->lchild, k);
		else if (ptr->key < k)
			return Search(ptr->rchild, k);
	}
}
bool BiSortTree::Search(int k)
{
	return Search(root, k) != NULL;
}

BiNode* BiSortTree::Search2(BiNode *ptr, int k)
{
	while (ptr)
	{
		if (k == ptr->key)
			return ptr;
		else if (k < ptr->key)
			ptr = ptr->lchild;
		else
			ptr = ptr->rchild;
	}
	return NULL;
}
bool BiSortTree::Search2(int k)
{
	return Search2(root, k) != NULL;
}

void BiSortTree::Delete(BiNode* &ptr, int k)
{
	if (ptr != NULL)
	{
		if (k < ptr->key)  Delete(ptr->lchild, k);
		else if (k > ptr->key) Delete(ptr->rchild, k);
		else
		{
			if (ptr->lchild != NULL && ptr->rchild != NULL)
			{
				BiNode *temp = ptr->lchild;
				while (temp->rchild != NULL) //寻找左子树中的最大值
					temp = temp->rchild;
				ptr->key = temp->key;
				Delete(ptr->lchild, temp->key);
			}
			else
			{
				BiNode *temp = ptr;
				if (ptr->lchild == NULL)
					ptr = ptr->rchild;
				if (ptr->rchild == NULL)
					ptr = ptr->lchild;
				delete temp;
			}
		}
	}
}
void BiSortTree::Delete(int k)
{
	Delete(root, k);
}

void BiSortTree::MidOrder(BiNode *ptr)
{
	if (ptr == NULL)
		return;
	MidOrder(ptr->lchild);
	cout << ptr->key << " ";
	MidOrder(ptr->rchild);
}
void BiSortTree::MidOrder()
{
	MidOrder(root);
}
