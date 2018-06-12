#include "MGraph.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main(void)
{
    int vexnum, edgenum;
    string vex;
    cout << "请输入有向图中的顶点数:";
    cin >> vexnum;
    vector<string> vexs;
    vexs.resize(vexnum);
    cout << "请依次输入这" << vexnum << "个顶点:";
    for (int i = 0; i < vexnum; i++)
        cin >> vexs[i];
    cout << "请输入有向图中的边数:";
    cin >> edgenum;
    MGraph A(vexs, edgenum);
    cout << "请输入起始顶点:";
    cin >> vex;
    A.ShortestPaths(vex);
    return 0;
}
