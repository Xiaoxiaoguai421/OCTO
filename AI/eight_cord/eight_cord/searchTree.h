#pragma once

#include<iostream>
#include<vector>
#include<queue>
#include<string>
using namespace std;
enum ACTION { Left,Up,Down,Right,Nothing };

struct Node
{
	size_t index;	//'0'������
	char cord[9];
	struct Node *parent;
	ACTION action;
	vector<Node*> children;	//�ӽڵ�
	int depth;
	//����ʽ����
	int f;
	struct Node* next;
};

class searchTree
{
private:
	Node* start;
	Node* target;
	deque<Node* > Open;
	deque<Node* > Closed;
	//����ʽʽ����
	Node Open_heuristic;
	Node Closed_heuristic;
	//tools
	void free(Node *p);
	void print_path(Node*  p,int& step);	
	void setCord(char *cord1, string cord2);
	void setCord(char *cord1, const char* cord2);
	void swap(char* a, size_t index_1, size_t index_2);
	void print(Node node);
	void show(bool bo);
	int missCord(Node* p);
	bool isEqual(Node v1, Node v2);
	bool isExist(Node node);
	Node* move(Node* node, ACTION act);

	bool bfs_expand(Node* node);
	bool dfs_expand(Node* node,bool& expand_able);
	void insert_open(Node* p);	//��Open�����
	void heu_expand(Node* node);	//��չ��㣬����f������open

public:
	bool _REACH;
	searchTree();
	~searchTree();
	void BFS();
	void DFS();
	void HEU();	//��������
	void print_path();	//��ӡ·��
};