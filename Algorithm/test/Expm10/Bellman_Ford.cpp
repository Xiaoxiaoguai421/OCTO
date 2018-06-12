/*
 * 最短路径
 * Bellman_Ford
*/

#include <iostream>
using namespace std;

bool BellmanFord(int source);
void update(int u, int v, int weight);

int main(void)
{
    char a[] = { 'A', 'B', 'C', 'D', 'E' };
    MGraph<char> m(a, 5, 8);
    cout << endl
         << "打印测试：" << endl;
    m.Print();
    m.Print_dist(1);
    return 0;
}

bool BellmanFord(int source)
{
    dist[source] = 0;
    for (int i = 1; i <= vexnum - 1; i++) {
        for (int u = 0; u < vexnum; u++) {
            for (int v = 0; v < vexnum; v++) {
                if (edges_view[u][v] == true) {
                    update(u, v, edges[u][v]);
                }
            }
        }
    }
    // 判断是否有负环路
    for (int u = 0; u < vexnum; u++) {
        for (int v = 0; v < vexnum; v++) {
            if (edges_view[u][v] == true) {
                if (dist[v] > dist[u] + edges[u][v]) {
                    return false;
                }
            }
        }
    }
    return true;
}

void update(int u, int v, int weight)
{
    if (dist[v] > dist[u] + weight)
        dist[v] = dist[u] + weight;
}
