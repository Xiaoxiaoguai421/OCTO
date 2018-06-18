#include "MGraph.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int VexToInt(string v, vector<string> vexs)
{
    int n = vexs.size();
    for (int i = 0; i < n; i++)
        if (v == vexs[i])
            return i;
    return -1;
}

int main(void)
{
    int vexnum, edgenum;
    string vex1, vex2;
    cout << "请输入有向图中顶点数：";
    cin >> vexnum;

    vector<string> vexs;
    vexs.resize(vexnum);
    cout << "请依次输入这" << vexnum << "个顶点：";
    for (int i = 0; i < vexnum; i++)
        cin >> vexs[i];

    cout << "请输入有向图中边数：";
    cin >> edgenum;

    vector<edge> edges;
    edges.resize(edgenum);
    cout << "请依次输入这" << edgenum << "条边的源顶点和目标顶点：" << endl;
    for (int i = 0; i < edgenum; i++) {
        cout << i + 1 << ':';
        cin >> vex1 >> vex2;
        edges[i].source = VexToInt(vex1, vexs);
        edges[i].dest = VexToInt(vex2, vexs);
    }
    MGraph A(vexs, edges);
    A.GetConnectivity();
    return 0;
}
