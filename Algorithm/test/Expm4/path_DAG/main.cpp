#include <iostream>
#include <string>
#include "MGraph.h"
using namespace std;

int main(void)
{
    int vexnum, edgenum;
    cout << "请输入顶点数：";
    cin >> vexnum;
    string* vexs = new string[vexnum];
    cout << "请依次输入这" << vexnum << "个顶点(从源点开始到终点结束)";
    for (int i = 0; i < vexnum; i++)
        cin >> vexs[i];
    cout << "请输入边数:";
    cin >> edgenum;
    MGraph A(vexs, vexnum, edgenum);
    A.MinPath();
    return 0;
}
