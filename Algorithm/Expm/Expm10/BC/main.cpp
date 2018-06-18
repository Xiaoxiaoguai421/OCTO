#include "MGraph.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(void)
{
    int vexnum, edgenum;
    cout << "请输入无向图中顶点数：";
    cin >> vexnum;
    vector<string> vexs;
    vexs.resize(vexnum);
    cout << "请依次输入这" << vexnum << "个顶点：";
    for (int i = 0; i < vexnum; i++)
        cin >> vexs[i];
    cout << "请输入无向图中边数：";
    cin >> edgenum;
    MGraph A(vexs, edgenum);
    cout << endl;
    A.DFSTraverse();
    return 0;
}
