#ifndef _MGRAPH_H_
#define _MGRAPH_H_

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class MGraph {
private:
    int vexnum, edgenum;
    vector<string> vexs;
    vector<vector<int> > edges;
    vector<int> indegree;

public:
    MGraph(string v[], int n, int e);
    ~MGraph(){};
    int GetVexValueNum(string v);
    void TopoSort(string Topo[]);
    void MinPath();
};

#endif
