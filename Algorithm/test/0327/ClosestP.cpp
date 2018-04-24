/*************************************************************************
    > File Name: ClosestP.cpp
    > Author: GZ
    > Mail: 194463810@qq.com
    > Created Time: 2018年04月17日 星期二 02时43分06秒
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;

const int MAXN = 100010;

struct Point
{
	double x;
	double y;
} P[MAXN], strip[MAXN];;

int N;

bool cmpX(Point p1, Point p2)
{
	if (p1.x != p2.x)   return p1.x < p2.x;
	return p1.y < p2.y;
}

bool cmpY(Point p1, Point p2)
{
	if (p1.y != p2.y)   return p1.y < p2.y;
	return p1.x < p2.x;
}

double dist(Point p1, Point p2)
{
	return sqrt( (p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y) );
}

double getStripDis(Point strip[], int n, double d)
{
	double rst = d;
	sort(strip, strip + n, cmpY);
	for (int i = 0; i < n; ++i)
	{
		for (int j = i + 1; j < n && (strip[j].y - strip[i].y) < rst; ++j)
		{
			if (dist(strip[i], strip[j]) < rst)
			{
				rst = dist(strip[i], strip[j]);
			}
		}
	}
	return rst;
}

double getClosestDis(Point Px[], int n)
{
	if (n == 1)     return INFINITY;
	if (n == 2)
		return dist(Px[0], Px[1]);
}
int mid = n / 2;
double x_mid = Px[mid].x;

double d_left = getClosestDis(Px, mid);
double d_right = getClosestDis(Px + mid, n - mid);
double d = min(d_left, d_right);

int k = 0;
for (int i = 0; i < n; ++i)
{
	if (abs(Px[i].x - x_mid) < d)
	{
		strip[k++] = Px[i];
	}
}
double d_strip = getStripDis(strip, k, d);
double d_final = d < d_strip ? d : d_strip;
return d_final;
}

int main()
{
	double rst;
	while (scanf("%d", &N) && N)
	{
		for (int i = 0; i < N; ++i)
		{
			scanf("%lf%lf", &P[i].x, &P[i].y);
		}
		sort(P, P + N, cmpX);
		rst = getClosestDis(P, N);
		printf("%.2lf\n", rst / 2);
	}
	return 0;
}
