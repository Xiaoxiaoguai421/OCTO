#ifndef _MGRAPH_H_
#define _MGRAPH_H_

#include <iostream>
#include <vector>
using namespace std;
typedef struct {
    int source;
    int dest;
    int weight;
} edge;

class MGraph {
private:
    int vexnum, edgenum;
    vector<string> vexs;         //顶点表
    vector<edge> edges;          //边表
    vector<vector<int> > matrix; //邻接矩阵
    void Update(edge e, int* dist, vector<vector<int> >& path);

public:
    MGraph(vector<string> v, int e);
    ~MGraph(){};
    int GetVexValueNum(string v); //返回顶点表中值的序号
    void ShortestPaths(string vex);
};

#endif
