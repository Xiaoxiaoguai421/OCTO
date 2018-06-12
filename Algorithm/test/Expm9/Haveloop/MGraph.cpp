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
    cout << "请依次输入这" << edgenum << "条边的源顶点和目标顶点：" << endl;
    for (int i = 0; i < edgenum; i++) {
        cout << setw(2) << i + 1 << ':';
        cin >> vexa >> vexb;
        va = GetVexValueNum(vexa);
        vb = GetVexValueNum(vexb);
        matrix[va][vb] = 1;
        edges[i].source = va;
        edges[i].dest = vb;
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

void MGraph::DFS(int v, vector<timestamp>& timestamps)
{
    timestamps[v].pre = count++;
    for (int i = 0; i < vexnum; i++)
        if (matrix[v][i] == 1 && timestamps[i].pre == 0)
            DFS(i, timestamps);
    timestamps[v].post = count++;
}

void MGraph::DFSTraverse()
{
    vector<timestamp> timestamps;
    timestamps.resize(vexnum);
    for (int i = 0; i < vexnum; i++)
        timestamps[i].pre = 0;
    count = 1;
    for (int i = 0; i < vexnum; i++)
        if (timestamps[i].pre == 0)
            DFS(i, timestamps);
    for (int i = 0; i < edgenum; i++)
        if (timestamps[edges[i].dest].pre < timestamps[edges[i].source].pre && timestamps[edges[i].source].post < timestamps[edges[i].dest].post) {
            cout << "图中存在环" << endl;
            return;
        }
    cout << "图中不存在环" << endl;
}
