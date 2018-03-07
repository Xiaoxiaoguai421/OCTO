/*************************************************************************
    > File Name: Huffman.h
    > Author:
    > Mail:
    > Created Time: 2017年11月28日 星期二 09时42分16秒
 ************************************************************************/

#ifndef _HUFFMAN_H
#define _HUFFMAN_H
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
struct HuffmanNode
{
	char data;
	double weight;
	int parent, lchild, rchild;
};

class HuffmanTree
{
public:
	HuffmanTree( vector<HuffmanNode> &leafs );
	~HuffmanTree() {};
	string GetCode(int i);
	string Decode(vector<int> &source);
	void Print();
private:
	vector<HuffmanNode> hufftree;
	int n;
	void SelectSmall(int &least, int &less, int i);
};
#endif
