#ifndef BFS_H
#define BFS_H
#include<iostream>
#include<vector>
#include<queue>
#include<string>
using namespace std;
namespace ns_bfs
{
enum ACTION { Left,Up,Down,Right,Nothing };
static const size_t INFINITY=9999;
struct Node
{
    size_t index;	//'0'的索引
    char code[9];
    struct Node *parent;
    ACTION action;
    vector<Node*> children;	//子节点
};
}
using namespace ns_bfs;

class bfs
{
private:
    ns_bfs::Node* start;
    ns_bfs::Node* target;
    deque<ns_bfs::Node* > Open;
    deque<ns_bfs::Node* > Closed;
    bool _REACH;
    //tools
    void free(ns_bfs::Node *p);
    size_t setCord(char *code1, string code2);
    void setCord(char *code1, const char* code2);
    void swap(char* a, size_t index_1, size_t index_2);
    bool isEqual(ns_bfs::Node* v1, ns_bfs::Node* v2);
    bool isExist(ns_bfs::Node* node);
    ns_bfs::Node* move(ns_bfs::Node* node, ns_bfs::ACTION act);

    bool bfs_expand(ns_bfs::Node* node);
public:
    bfs(string m_start,string m_target);
    ~bfs();
    void BfsSearch();
    unsigned long getOPEN() const;
    unsigned long getCLOSED() const;
    bool getREACH() const;
};

#endif // BFS_H
