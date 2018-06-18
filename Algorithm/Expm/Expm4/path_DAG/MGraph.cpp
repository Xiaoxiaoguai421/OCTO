#ifndef _MGRAPH_CPP_
#define _MGRAPH_CPP_

#include <iomanip>
#include <iostream>
#include <queue>
#include "MGraph.h"
#define infinity 9999
using namespace std;

MGraph::MGraph(string v[], int n, int e)
{
    vexnum = n;
    edgenum = e;
    vexs.resize(vexnum);
    edges.resize(vexnum);
    for (int i = 0; i < vexnum; i++)
        vexs[i] = v[i];
    for (int i = 0; i < vexnum; i++)
        edges[i].resize(vexnum);
    for (int i = 0; i < vexnum; i++) {
        for (int j = 0; j < vexnum; j++)
            if (i == j)
                edges[i][j] = 0;
            else
                edges[i][j] = infinity;
    }
    indegree.resize(vexnum);
    string vexa, vexb;
    int va, vb, w;
    cout << "请依次输入这" << edgenum << "条边的起点、终点以及权值：" << endl;
    for (int i = 0; i < edgenum; i++) {
        cout << setw(2) << i + 1 << ':';
        cin >> vexa >> vexb;
        va = GetVexValueNum(vexa);
        vb = GetVexValueNum(vexb);
        indegree[vb]++;
        cin >> w;
        edges[va][vb] = w;
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

void MGraph::TopoSort(string Topo[])
{
    int k = 0;
    queue<int> s;
    bool* visited = new bool[vexnum];
    for (int i = 0; i < vexnum; i++)
        visited[i] = false;
    for (int i = 0; i < vexnum; i++) {
        if (!indegree[i]) {
            visited[i] = true;
            Topo[k++] = vexs[i];
            s.push(i);
        }
    }
    while (!s.empty()) {
        int i = s.front();
        s.pop();
        for (int j = 0; j < vexnum; j++) {
            if (!visited[j]) {
                if (edges[i][j] != infinity && edges[i][j] != 0)
                    indegree[j]--;
                if (!indegree[j]) {
                    visited[j] = true;
                    Topo[k++] = vexs[j];
                    s.push(j);
                }
            }
        }
    }
}

void MGraph::MinPath()
{
    string* Topo = new string[vexnum];
    TopoSort(Topo);
    int* path = new int[vexnum];
    int* dist = new int[vexnum];
    dist[0] = 0;
    path[0] = 0;
    for (int j = 1; j < vexnum; j++) {
        dist[j] = infinity;
        for (int i = 0; i < j; i++)
            if (dist[j] > dist[i] + edges[GetVexValueNum(Topo[i])][GetVexValueNum(Topo[j])]) {
                dist[j] = dist[i] + edges[GetVexValueNum(Topo[i])][GetVexValueNum(Topo[j])];
                path[j] = i;
            }
    }
    cout << "从源点" << vexs[0] << "到终点" << vexs[vexnum - 1] << "的最短路径为：" << Topo[0];
    vector<int> s;
    s.push_back(vexnum - 1);
    while (s.back() != 0)
        s.push_back(path[s.back()]);
    s.pop_back();
    while (!s.empty()) {
        int j = s.back();
        s.pop_back();
        cout << "-->" << Topo[j];
    }
    cout << "    最短路径的长度为：" << dist[vexnum - 1] << endl;
}

#endif
