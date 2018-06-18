//
//树中最大独立集
//
//
#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;
void readTree();
void dfs(int u, int fa);
int rootDp(int u);

const int MAXN = 100;
vector<int> G[MAXN]; //G[i]表示顶点i的邻接点
int l[MAXN];         //结点层次
int p[MAXN];         //根树
int dp[MAXN];        //dp数组
int sumC[MAXN];      //孩子DP和
int sumS[MAXN];      //孙子DP和
int maxL;            //最大层次
int n;

int main(void)
{
    readTree();
    int res = -1;
    //分别以每个顶点为根
    for (int i = 0; i < n; ++i) {
        memset(sumS, 0, sizeof(sumS));
        memset(sumC, 0, sizeof(sumC));
        int tmp;
        if ((tmp = rootDp(i)) > res)
            res = tmp;
    }
    cout << res << endl;
    return 0;
}

void readTree()
{
    int u, v;
    cin >> n;
    for (int i = 0; i < n - 1; ++i) {
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
}
void dfs(int u, int fa)
{
    int d = G[u].size();
    l[u] = (fa == -1) ? 0 : (l[fa] + 1);
    if (l[u] > maxL) {
        maxL = l[u];
    }
    for (int i = 0; i < d; ++i) {
        int v = G[u][i];
        if (v != fa) {
            dfs(v, p[v] = u);
        }
    }
}
int rootDp(int u)
{
    // 构造u根树
    p[u] = -1;
    maxL = -1;
    dfs(u, p[u]);
    for (int i = maxL; i >= 0; --i) {
        for (int j = 0; j < n; ++j) {
            if (l[j] == i) {
                if (sumS[j] + 1 > sumC[j]) {
                    dp[j] = sumS[j] + 1;
                } else
                    dp[j] = sumC[j];
                if (i - 1 >= 0) {
                    sumC[p[j]] += dp[j];
                }
                if (i - 2 >= 0) {
                    sumS[p[p[j]]] += dp[j];
                }
            }
        }
    }
    return dp[u];
}
