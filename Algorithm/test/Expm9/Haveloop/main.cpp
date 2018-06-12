#include <iostream>
#include <string>
#include <vector>
#include "MGraph.h"
using namespace std;
int main(void)
{
    int vexnum, edgenum;
    cout << "请输入有向图中顶点数：";
    cin >> vexnum;
    vector<string> vexs;
    vexs.resize(vexnum);
    cout << "请依次输入这" << vexnum << "个顶点：";
    for (int i = 0; i < vexnum; i++)
        cin >> vexs[i];
    cout << "请输入有向图中边数：";
    cin >> edgenum;
    MGraph A(vexs, edgenum);
    A.DFSTraverse();
    return 0;
}
