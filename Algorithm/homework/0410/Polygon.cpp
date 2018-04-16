/*************************************************************************
    > File Name: Polygon.cpp
    > Author: GZ
    > Mail: 194463810@qq.com
    > Created Time: 2018年04月16日 星期一 22时01分00秒
 ************************************************************************/

#include<iostream>
#include<math.h>
#include<vector>
using namespace std;
struct Point
{
	int x, y;
};
double cost(Point a, Point b);
void MinTriangulation(vector<Point> p);
int main(void)
{
	int n = 0;
	cout << "请输入顶点个数：";
	cin >> n;
	vector<Point> p(n + 1);
	cout << "请输入凸多边形的顶点\n$:";
	for (int i = 1; i <= n; i++)
		cin >> p[i].x >> p[i].y;
/*
	cout << "输入的点为" << endl;
	for (int i = 0; i <= n; i++)
		cout << "(" << p[i].x << "," << p[i].y << ")" << endl;
*/
	MinTriangulation(p);
	return 0;
}

void MinTriangulation(vector<Point> p)
{
	int n = p.size();
	vector<vector<double> > a(n + 1);
	for (int i = 1; i <= n; i++)
		a[i].resize(n + 1);

	for (int i = 1; i <= n; i++)
		a[i][i] = 0;
	for (int gap = 2; gap <= n; gap++)
		for (int i = 1; i <= n - gap + 1; i++)
		{
			int j = i + gap - 1;
			for (int k = i + 1; k <= j - 1; k++)
			{
				if (k == i + 1)
					a[i][j] = cost(p[k], p[j]) + a[k][j];
				else if (k == j - 1)
					a[i][j] = cost(p[k], p[i]) + a[i][k];
				else    a[i][j] = cost(p[k], p[j]) + cost(p[k], p[i]) + a[k][j] + a[i][k];
			}
		}
	cout << "最小三角剖分代价:" << a[1][n] << endl;
}

double cost(Point a, Point b)
{
	return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}
