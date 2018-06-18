#ifndef _MGRAPH_H_
#define _MGRAPH_H_

#include <iostream>
#include <vector>
using namespace std;

typedef struct {
    int pre;
    int back;
} timestamp;

typedef struct {
    int source;
    int dest;
} edge;

class MGraph {
private:
    int vexnum, edgenum;
    int count;
    vector<string> vexs;         //顶点表
    vector<edge> edges;          //边表
    vector<vector<int> > matrix; //邻接矩阵
    void bicompDFS(int v, vector<timestamp>& timestamps, bool* visited, vector<edge>& edgeStack, vector<vector<int> >& bicomponents);
    int GetEdgeNum(int u, int v);
    void GetBicomponent(int j, vector<edge>& edgeStack, vector<int>& bicomponent);

public:
    MGraph(vector<string> v, int e);
    ~MGraph(){};
    int GetVexValueNum(string v); //返回顶点表中值的序号
    void DFSTraverse();
};

#endif
