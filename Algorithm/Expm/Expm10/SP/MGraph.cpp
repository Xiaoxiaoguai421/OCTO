#include "MGraph.h"
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>
#define infinity 999999
using namespace std;

MGraph::MGraph(vector<string> v, int e)
{
    vexnum = v.size();
    edgenum = e;
    vexs.resize(vexnum);
    matrix.resize(vexnum);
    for (int i = 0; i < vexnum; i++)
        vexs[i] = v[i];
    for (int i = 0; i < vexnum; i++)
        matrix[i].resize(vexnum);
    for (int i = 0; i < vexnum; i++) {
        for (int j = 0; j < vexnum; j++)
            matrix[i][j] = 0;
    }
    string vexa, vexb;
    int va, vb, w;
    edges.resize(edgenum);
    cout << "请依次输入这" << edgenum << "条边的源顶点、目标顶点以及权值：" << endl;
    for (int i = 0; i < edgenum; i++) {
        cout << setw(2) << i + 1 << ':';
        cin >> vexa >> vexb >> w;
        va = GetVexValueNum(vexa);
        vb = GetVexValueNum(vexb);
        matrix[va][vb] = w;
        edges[i].source = va;
        edges[i].dest = vb;
        edges[i].weight = w;
    }
}

int MGraph::GetVexValueNum(string v)
{
    int i;
    for (i = 0; i < vexnum; i++)
        if (vexs[i] == v)
            break;
    if (i == vexnum)
        return -1;
    else
        return i;
}

void MGraph::Update(edge e, int* dist, vector<vector<int> >& path)
{
    int u = e.source;
    int v = e.dest;
    if (dist[v] > dist[u] + matrix[u][v]) {
        dist[v] = dist[u] + matrix[u][v];
        path[v].clear();
        path[v] = path[u];
        path[v].push_back(v);
    }
}

void MGraph::ShortestPaths(string vex)

{
    int v = GetVexValueNum(vex);
    int* dist = new int[vexnum];
    for (int i = 0; i < vexnum; i++)
        dist[i] = infinity;
    vector<vector<int> > path;
    path.resize(vexnum);
    dist[v] = 0;
    for (int i = 0; i < vexnum - 1; i++)
        for (int j = 0; j < edgenum; j++)
            Update(edges[j], dist, path);
    for (int j = 0; j < edgenum; j++) {
        int u = edges[j].source;
        int v = edges[j].dest;
        if (dist[v] > dist[u] + matrix[u][v]) {
            cout << "error:图中存在负环!" << endl;
            return;
        }
    }
    for (int i = 0; i < vexnum; i++)
        if (i != v) {
            cout << "从顶点" << vex << "到顶点" << vexs[i] << "的最短路径长度为:" << dist[i];
            cout << "     路径为:" << vex;
            for (int j = 0; j < path[i].size(); j++)
                cout << "-->" << vexs[path[i][j]];
            cout << endl;
        }
}
