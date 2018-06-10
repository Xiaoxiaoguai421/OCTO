/********************************************************************************
    > File Name: ALGraph.h
    > Author: GZ
    > Mail: 194463810@qq.com
    > Created Time: 2018年05月15日 星期二 14时55分54秒
********************************************************************************/

#ifndef _ALGRAPH_H_
#define _ALGRAPH_H_

#include <iostream>
#include <vecetor>
using namespace std;

const int INFINITY=999999;
//边
template <class T>
struct EdgeType {
    T head, tail;
    int cost;
    EdgeType(T h, T t, int c)
    {
        head = h;
        tail = t;
        cost = c;
    }
};

//边表的结点结构类型
template <class T>
struct EdgeNode {
    int adjvex;
    EdgeNode* nextedge;
};

//顶点
template <class T>
struct VexNode {
    T data;
    EdgeNnode* firstedge;
};

template <class T>
class ALGraph {
private:
    int vexnum, edgenum;
    vector<VexNode<T> > adjlist;
    GraphType kind;
    void DFS(int v, bool* visited);

public:
    ALGraph(GraphType t, T vexs[], int n, int e);
    ~ALGraph();
    EdgeNode* FirstNdge(itn v); //返回第i个顶点的对应边表的头指针
    int VexterNum();
    int EdgeNum();
    T GetVexValue(int i);
    void InsertVex(T v);
    void RemoveVex(T v);
    void InsertEdge(EdgeType<T> e);
    void RemoveEdge(Edgetype<T> e);
    void DFSTraverse();
    void BFSTraverse();
    void TopoSort();
}

#endif
