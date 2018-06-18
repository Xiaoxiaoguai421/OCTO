#include "MGraph.h"
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>
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
    int va, vb;
    edges.resize(edgenum);
    cout << "请依次输入这" << edgenum << "条边的两个端点：" << endl;
    for (int i = 0; i < edgenum; i++) {
        cout << setw(2) << i + 1 << ':';
        cin >> vexa >> vexb;
        va = GetVexValueNum(vexa);
        vb = GetVexValueNum(vexb);
        matrix[va][vb] = matrix[vb][va] = 1;
        edges[i].source = (va < vb) ? va : vb;
        edges[i].dest = (va < vb) ? vb : va;
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

int MGraph::GetEdgeNum(int u, int v)
{
    int max = (u > v) ? u : v;
    int min = (u > v) ? v : u;
    for (int i = 0; i < edgenum; i++)
        if (min == edges[i].source && max == edges[i].dest)
            return i;
    return -1;
}

void MGraph::GetBicomponent(int j, vector<edge>& edgeStack, vector<int>& bicomponent)
{
    bool* visited = new bool[vexnum];
    for (int i = 0; i < vexnum; i++)
        visited[i] = false;
    edge temp = edgeStack.back();
    while (GetEdgeNum(temp.source, temp.dest) != j) {
        edgeStack.pop_back();
        visited[temp.source] = true;
        visited[temp.dest] = true;
        temp = edgeStack.back();
    }
    edgeStack.pop_back();
    visited[temp.source] = true;
    visited[temp.dest] = true;
    for (int i = 0; i < vexnum; i++)
        if (visited[i])
            bicomponent.push_back(i);
}

void MGraph::bicompDFS(int v, vector<timestamp>& timestamps, bool* visited, vector<edge>& edgeStack, vector<vector<int> >& bicomponents)
{
    timestamps[v].pre = count++;
    timestamps[v].back = timestamps[v].pre;
    for (int i = 0; i < vexnum; i++)
        if (matrix[v][i] == 1 && !visited[GetEdgeNum(v, i)]) {
            edgeStack.push_back(edges[GetEdgeNum(v, i)]);
            visited[GetEdgeNum(v, i)] = true;
            if (timestamps[i].pre == 0) {
                bicompDFS(i, timestamps, visited, edgeStack, bicomponents);
                int iBack = timestamps[i].back;
                if (iBack >= timestamps[v].pre) {
                    vector<int> bicomponent;
                    GetBicomponent(GetEdgeNum(v, i), edgeStack, bicomponent);
                    bicomponents.push_back(bicomponent);
                }
                if (timestamps[v].back > iBack)
                    timestamps[v].back = iBack;
            } else if (timestamps[v].pre > timestamps[i].pre)
                if (timestamps[v].back > timestamps[i].pre)
                    timestamps[v].back = timestamps[i].pre;
        }
}

void MGraph::DFSTraverse()
{
    vector<timestamp> timestamps;
    timestamps.resize(vexnum);
    for (int i = 0; i < vexnum; i++)
        timestamps[i].pre = 0;

    bool* visited = new bool[edgenum];
    for (int i = 0; i < edgenum; i++)
        visited[i] = false;

    vector<edge> edgeStack;
    vector<vector<int> > bicomponents;
    count = 1;
    for (int i = 0; i < vexnum; i++)

        if (timestamps[i].pre == 0)

            bicompDFS(i, timestamps, visited, edgeStack, bicomponents);

    int* num = new int[vexnum];
    for (int i = 0; i < vexnum; i++)
        num[i] = 0;

    for (int i = 0; i < bicomponents.size(); i++) {
        for (int j = 0; j < bicomponents[i].size(); j++) {
            num[bicomponents[i][j]]++;
            cout << vexs[bicomponents[i][j]] << " ";
        }
        cout << "为图中的一个双连通分量" << endl;
    }
    cout << endl;

    cout << "图中的关节点为:";
    for (int i = 0; i < vexnum; i++)
        if (num[i] > 1)
            cout << vexs[i] << " ";
    cout << endl;
}
