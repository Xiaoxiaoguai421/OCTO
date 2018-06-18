#include "MGraph.h"
#include <algorithm>
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

MGraph::MGraph(vector<string> v, vector<edge> e)
{
    vexnum = v.size();
    edgenum = e.size();
    vexs = v;
    edges = e;
    matrix.resize(vexnum);
    for (int i = 0; i < vexnum; i++)
        matrix[i].resize(vexnum);
    for (int i = 0; i < vexnum; i++) {
        for (int j = 0; j < vexnum; j++)
            matrix[i][j] = 0;
    }
    int v1, v2;
    for (int i = 0; i < edgenum; i++) {
        v1 = e[i].source;
        v2 = e[i].dest;
        matrix[v1][v2] = 1;
    }
}

void MGraph::DFS(int v, vector<timestamp>& timestamps)
{
    timestamps[v].pre = count++;
    for (int i = 0; i < vexnum; i++)
        if (matrix[v][i] == 1 && timestamps[i].pre == 0)
            DFS(i, timestamps);
    timestamps[v].post = count++;
}

bool comp(timestamp& a, timestamp& b)
{
    return a.post > b.post;
}

void MGraph::DFSTraverse(vector<timestamp>& timestamps)
{
    timestamps.resize(vexnum + 1);
    for (int i = 0; i < vexnum; i++) {
        timestamps[i].pre = 0;
        timestamps[i].vex = vexs[i];
    }
    count = 1;
    for (int i = 0; i < vexnum; i++)
        if (timestamps[i].pre == 0)
            DFS(i, timestamps);
    sort(&timestamps[0], &timestamps[vexnum], comp);
}

void MGraph::Explore(int v, bool* visited, vector<string>& connectivity)
{
    connectivity.push_back(vexs[v]);
    visited[v] = true;
    for (int i = 0; i < vexnum; i++)
        if (matrix[v][i] == 1 && !visited[i])
            Explore(i, visited, connectivity);
}

int MGraph::GetVexValueNum(string v)
{
    for (int i = 0; i < vexnum; i++)
        if (v == vexs[i])
            return i;
    return -1;
}

void MGraph::GetConnectivity()
{
    vector<edge> inversion;
    inversion.resize(edgenum);
    for (int i = 0; i < edgenum; i++) {
        inversion[i].source = edges[i].dest;
        inversion[i].dest = edges[i].source;
    }

    MGraph B(vexs, inversion);
    vector<timestamp> timestamps;
    B.DFSTraverse(timestamps);
    bool* visited = new bool[vexnum];
    for (int i = 0; i < vexnum; i++)
        visited[i] = false;

    vector<vector<string> > connectivities;
    vector<string> connectivity;
    for (int i = 0; i < vexnum; i++) {
        int j = GetVexValueNum(timestamps[i].vex);
        if (!visited[j]) {
            connectivity.clear();
            Explore(j, visited, connectivity);
            connectivities.push_back(connectivity);
        }
    }

    for (int i = 0; i < connectivities.size(); i++) {
        for (int j = 0; j < connectivities[i].size(); j++)
            cout << connectivities[i][j] << " ";
        cout << "是该图的一个强连通分量" << endl;
    }
}
