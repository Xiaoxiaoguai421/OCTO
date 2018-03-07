/*************************************************************************
    > File Name: Huffman.cpp
    > Author:
    > Mail:
    > Created Time: 2017年11月28日 星期二 09时42分59秒
 ************************************************************************/

#include"Huffman.h"

void HuffmanTree::SelectSmall(int &least, int &less, int i)
{
	int j = 0;
	while (hufftree[j].parent != -1)
		j++;
	least = less = j;
	for (j = 0; j < i; j++)
		if (hufftree[j].parent == -1)
			if (hufftree[j].weight < hufftree[least].weight)
				least = j;
	if (least == less)
	{
		j = least + 1;
		while (hufftree[j].parent != -1)
			j++;
		less = j;
	}
	for (j = 0; j < i; j++)
		if (hufftree[j].parent == -1 && j != least)
			if (hufftree[j].weight < hufftree[less].weight)
				less = j;
}

HuffmanTree::HuffmanTree(vector<HuffmanNode> &leafs)
{
	n = leafs.size();
	hufftree.resize(2 * n - 1);
	for (int i = 0; i < n; i++)
	{
		hufftree[i].data = leafs[i].data;
		hufftree[i].weight = leafs[i].weight;
		hufftree[i].parent = hufftree[i].lchild = hufftree[i].rchild = -1;
	}
	for (int i = n; i < 2 * n - 1; i++)
	{
		int least, less;
		SelectSmall(least, less, i);
		hufftree[least].parent = hufftree[less].parent = i;
		hufftree[i].parent = -1;
		hufftree[i].lchild = least;
		hufftree[i].rchild = less;
		hufftree[i].weight = hufftree[least].weight + hufftree[less].weight;
	}
}

void HuffmanTree::Print()
{
	for (int i = 0; i < hufftree.size(); i++)
		cout << hufftree[i].data << " " << hufftree[i].weight << " " << hufftree[i].parent << " " << hufftree[i].lchild << " " << hufftree[i].rchild << endl;
}

string HuffmanTree::GetCode(int i)
{
	string code;
	int p = i;
	int parent = hufftree[i].parent;
	while (parent != -1)
	{
		if (hufftree[parent].lchild == p)
			code += "0";
		else
			code += "1";
		p = parent;
		parent = hufftree[parent].parent;
	}
	reverse(code.begin(), code.end());  //逆置
	return code;
}

string HuffmanTree::Decode(vector<int> &source)
{
	string target = "";
	int root = hufftree.size() - 1;
	int p = root;
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
