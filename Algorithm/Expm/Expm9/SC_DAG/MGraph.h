#ifndef _MGRAPH_H_
#define _MGRAPH_H_

#include <iostream>
#include <vector>
using namespace std;

typedef struct {
    string vex;
    int pre;
    int post;
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
    void DFS(int v, vector<timestamp>& timestamps);

public:
    MGraph(vector<string> v, vector<edge> e);
    ~MGraph(){};
    int GetVexValueNum(string v);
    void Explore(int v, bool* visited, vector<string>& connectivity);
    void DFSTraverse(vector<timestamp>& timestamps);
    void GetConnectivity();
};

#endif
