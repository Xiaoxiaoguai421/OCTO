#ifndef HEU_H
#define HEU_H
#include <iostream>
#include <vector>
#include<string>
using namespace std;
namespace ns_heu
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
    int f;
    struct Node* next;
};
}
using namespace ns_heu;

class heu
{
private:
    ns_heu::Node* start;
    ns_heu::Node* target;
    ns_heu::Node Open_heuristic;    //头结点
    ns_heu::Node Closed_heuristic;
    bool _REACH;
    //tools
    void free(ns_heu::Node *p);
    void free_tab(ns_heu::Node *p);
    size_t setCord(char *code1, string code2);
    void setCord(char *code1, const char* code2);
    void swap(char* a, size_t index_1, size_t index_2);
    bool isEqual(ns_heu::Node* v1, ns_heu::Node* v2);
    ns_heu::Node* move(ns_heu::Node* node, ns_heu::ACTION act);

    int missCord(ns_heu::Node* p);
    void insert_open(ns_heu::Node* p);	//向Open表插入
    void heu_expand(ns_heu::Node* node);
public:
    heu(string m_start,string m_target);
    ~heu();
    void HeuSearch();
    unsigned long getOPEN() const;
    unsigned long getCLOSED() const;
    bool getREACH() const;
};

#endif // HEU_H
