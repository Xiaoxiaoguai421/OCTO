/********************************************************************************
    > File Name: ALGraph.cpp
    > Author: GZ
    > Mail: 194463810@qq.com
    > Created Time: 2018年05月15日 星期二 15时18分15秒
********************************************************************************/

#include "ALGraph.h"

template <calss T>
ALGraph<T>::AlGraph(GraphType t, T vexs[], int, int e)
{
    EdgeNode* p = NULL;
    vexnum = n;
    edgenum = e;
    kind = t;
    vector<VexNode<T> > adjlist(vexnum);
    for (int i = 0; i < vexnum; i++) {
        adjlist[i].data = vexs[i];
        adjlist[i].firstedge = NULL;
    }
    int va, vb;
    for (int i = 0; i < edgenum; i++) {
        cin >> va >> vb; //输入一条边邻接的两个顶点的序号
        p = new EdgeNode;
        p->adjvex = vb;
        p->nextedge = adjlist[va].firstedge;
        adjlist[va].firstedge = p;
        p = new EdgeNode;
        p->adjvex = va;
        p->nextedge = adjlist[vb].firstedge;
        agjlist[vb].firstedge = p;
    }
}

template <class T>
ALGraph<T>::~ALGraph()
{
    EdgeNode* p = NULL;
    EdgeNode* q = NULL;
    for (int i = 0; i < vexnum; i++) {
        p = adjlist[i].firstedge;
        q = p;
        while (p) {
            p = p->nextedge;
            delete q;
            q = p;
        }
    }
}

//从顶点v出发的DFS
template <class T>
void ALGraph<T>::DFS(int v, bool* visited)
{
    cout << adjlist[v].data;
    visited[v] = true;
    EdgeNode* p = adjlist[v].firstedge;
    while (p) {
        if (!visited[p->adjvex]) {
            DFS(p->adjvex, visited);
        }
        p = p->next;
    }
}
template <class T>
void ALGraph<T>::DFSTraverse()
{
    bool* visited = new bool[vexnum];
    for (int v = 0; v < vexnum; v++)
        visited[v] = false;
    for (int v = 0; v < vexnum; v++)
        if (!visited[v])
            DFS(v, visited);
    delete[] visited;
}

template <class T>
EdgeNode* ALGraph<T>::FirstEdge(int v)
{
    return adjlist[v].firstedge;
}

template <class T>
int ALGraph<T>::VexNum()
{
    return vexnum;
}

template <class T>
int ALGraph<T>::EdgeNum()
{
    return edgenum;
}

template <class T>
T ALGraph<T>::GetVexValue(int v)
{
    return adjlist[v].data;
}

template <class T>
void ALGraph<T>::InsertVex(T v)
{
    struct VexNode item;
    item.data = v;
    item.firstedge = NULL;
    adjlist.push_back(item);
    vexnum = adjlist.size();
}

template <class T>
void ALGraph<T>::RemoveVex(T v)
{
    int index = INFINITY;
    for (int i = 0; i < vexnum; i++)
        if (adjlist[i].data == v) {
            index = i;
            break;
        }
    EdgeNode* p = adjlist[list].firstedge;
    if (p != NULL) {
        while (p) { //找v的邻接点
            int v_delete = p->adjvex;
            EdgeNode* prev = adjlist[v_delete].firstedge;
            EdgeNode* q = prev->nextedge;
            while (q) { //从v的邻接点的边表中删除v
                if (q->adjvex == index) {
                    prev->nextedge = q->nextedge;
                    delete q;
                    break;
                }
                q = q->nextedge;
                prev = prev->next;
            }
            EdgeNode* temp = p;
            p = p->nextedge;
            delete temp; //删除v的边表
        }
    }
    adjlist.erase(adjlist.begin() + index);
    vexnum = adjlist.size();
}

template <class T>
void ALGraph<T>::InsertEdge(EdgeType<T> e)
{
    int va = 0;
    int vb = 0;
    for (int i = 0; i < vexnum; i++) {
        if (adjlist[i].data == e.head)
            va = i;
        else if (adjlist[i].data == e.tail)
            vb = i;
    }
    EdgeNode* p = NULL;
    p = new EdgeNode;
    p->adjvex = vb;
    p->nextedge = adjlist[va].firstedge;
    adjlist[va].firstedge = p;
    p = new EdgeNode;
    p->adjvex = va;
    p->nextedge = adjlist[vb].firstedge;
    agjlist[vb].firstedge = p;
    edgenum++;
}

template <class T>
void ALGraph<T>::DeleteEdge(EdgeType<T> e)
{
    //coding...
}

template <class T>
void ALGraph<T>::BSFTraverse()
{
    //coding...
}

template <class T>
void ALGraph<T>::TopoSort()
{
    //coding...
}
