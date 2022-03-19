#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>
#define dista(i,j) dist(num[i][0], num[j][0],num[i][1], num[j][1],num[i][2], num[j][2],num[i][3], num[j][3])
using namespace std;
struct node
{
	int to;
	double w;
	node(int a, double b)
	{
		to = a, w = b;
	}
	bool operator<(const node& a)const
	{
		return this->w > a.w;
	}
};
double dis[105];
int vis[105];
vector<node>E[105];
double prim(int n)
{
	for (int i = 1; i <= n; ++i)
		dis[i] = 1e9;
	memset(vis, 0, sizeof(vis));
	priority_queue<node>que;
	dis[1] = 0;
	double sum = 0;
	que.push(node(1, dis[1]));
	while (!que.empty())
	{
		int u = que.top().to;
		double w = que.top().w;
		que.pop();
		if (vis[u])
			continue;
		vis[u] = 1;
		sum += w;
		for (int i = 0; i < E[u].size(); ++i)
		{
			int v = E[u][i].to;
			w = E[u][i].w;
			if (w < dis[v])
			{
				dis[v] = w;
				que.push(node(v, dis[v]));
			}
		}
	}
	return sum;
}
double dist(double x1, double x2, double y1, double y2, double z1, double z2, double r1, double r2)
{
	double ans = sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2) + (z1 - z2) * (z1 - z2)) - r1 - r2;
	return ans > 0 ? ans : 0;
}
double num[105][4];
#include <cstdio>
int main()
{
	int n;
	while (cin >> n && n)
	{
		for (int i = 1; i <= n; ++i)
			E[i].clear();
		for (int i = 1; i <= n; ++i)
			for (int j = 0; j < 4; ++j)
				cin >> num[i][j];
		for (int i = 1; i <= n; ++i)
			for (int j = 1; j <= n; ++j)
			{
				E[i].push_back(node(j, dista(i, j)));
			}
		printf("%.3lf\n", prim(n));
	}
	return 0;
}