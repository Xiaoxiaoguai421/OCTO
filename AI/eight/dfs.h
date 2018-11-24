#ifndef DFS_H
#define DFS_H
#include<iostream>
#include<vector>
#include<queue>
#include<string>
using namespace std;
namespace  ns_dfs
{
enum ACTION { Left,Up,Down,Right,Nothing };
const size_t INFINITY=9999;
struct Node
{
    size_t index;	//'0'的索引
    char code[9];
    struct Node *parent;
    ACTION action;
    vector<Node*> children;	//子节点
    int depth;
};
}
using namespace ns_dfs;

class dfs
{
private:
    ns_dfs::Node* start;
    ns_dfs::Node* target;
    deque<ns_dfs::Node* > Open;
    deque<ns_dfs::Node* > Closed;
    bool _REACH;
    int DEPTH;
    //tools
    void free(ns_dfs::Node *p);
    size_t setCord(char *code1, string code2);
    void setCord(char *code1, const char* code2);
    void swap(char* a, size_t index_1, size_t index_2);
    bool isEqual(ns_dfs::Node* v1, ns_dfs::Node* v2);
    bool isExist(ns_dfs::Node* node);
    ns_dfs::Node* move(ns_dfs::Node* node, ns_dfs::ACTION act);

    bool dfs_expand(ns_dfs::Node* node,bool& expand_able);
public:
    dfs(string m_start,string m_target,int dep);
    ~dfs();
    void DfsSearch();
    unsigned long getOPEN() const;
    unsigned long getCLOSED() const;
    bool getREACH() const;
};

#endif // DFS_H
