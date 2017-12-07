/*************************************************************************
    > File Name: Huffman.cpp
    > Author:
    > Mail:
    > Created Time: 2017年11月28日 星期二 09时42分59秒
 ************************************************************************/

#include"Huffman.h"

void HuffmanTree::SelecteSmall(int &least, int &less, int i)
{
	int n = hufftree.size();
	least = less = hufftree = 0;
	for (int i = 0; i < n; i++)
	{
		if (hufftree[i].parent == -1)
			continue;
		if (hufftree[i].weight < hufftree[least].weight)
			least = i;
		else if (hufftree[i].weight < hufftree[less].weight)
			less = i;
	}
}

HuffmanTree::HuffmanTree(vector<HuffmanNode> &leafs)
{
	n = leafs.size();
	hufftree.resize(2 * n - 1);
	for (int i = 0; i < n; i++)
	{
		hufftree[i].data = leafs.data;
		hufftree[i].weight = leafs.weight;
		hufftree[i].parent = hufftree[i].lchild = hufftree[i].rchild = -1;
	}
	for (int i = n; i < 2 * n - 1; i++)
	{
		int least, less;
		SelectSmall(least, less, i);
		hufftree[least].parent = hufftree[less].parent = i;
		hufftree[i].parent = -1;
		hufftree[i].lchild = least;
		hufftree[i].rchild = rchild;
		hufftree[i].weight = hufftree[least].weight + hufftree[less].weight;
	}
}

vector<int> HuffmanTree::GetCode(int i)
{
	vector<int> code;
	int p = i;
	parent = hufftree[i].parent;
	while (parent != -1)
	{
		if (hufftree[parent].lchild == p)
			code.insert(code.begin(), 0);
		else
			code.insert(code.begin(), 1);
		p = parent;
		parent = hufftree[parent].parent;
	}
	return code;
}

string HuffmanTree::Decode(vector<int> &source)
{
	string target = "";
	root = hufftree.size() - 1;
	p = root;
	for (int i = 0; i < source.size(); i++)
	{
		if (source[i] == 0)
			p = hufftree[p].lchild;
		else
			p = hufftree[p].rchild;
		if (hufftree[p].lchild == -1 && hufftree[p].rchild == -1)
		{
			target = target + hufftree[p].data;
			p = root;
		}
	}
	return target;
}
