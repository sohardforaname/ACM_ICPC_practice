#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <cstdio>
using namespace std;
struct node
{
	int to;
	double cost;
	bool operator<(const node &a)const
	{
		return this->cost > a.cost;//!!!
	}
};
int x[205], y[205];
vector<node>Edge[205];
double dis[205];
int vis[205];
void dij(int n)
{
	priority_queue<node>que;
	while (!que.empty())
		que.pop();
	for (int i = 1; i <= n; ++i)
		dis[i] = 1e9;
	node tmp;
	memset(vis, 0, sizeof(vis));
	dis[1] = 0;
	tmp.to = 1, tmp.cost = dis[1];
	que.push(tmp);
	while (!que.empty())
	{
		int to = que.top().to;
		que.pop();
		if (vis[to])
			continue;
		vis[to] = 1;
		for (int i = 0; i < Edge[to].size(); ++i)
		{
			int v = Edge[to][i].to;
			if (max(dis[to], Edge[to][i].cost) < dis[v])
			{
				dis[v] = max(dis[to], Edge[to][i].cost);
				tmp.to = v, tmp.cost = dis[v];
				que.push(tmp);
			}
		}
	}
}
double len(int a1, int a2, int b1, int b2)
{
	return sqrt(double((a1 - a2) * (a1 - a2) + (b1 - b2) * (b1 - b2)));
}
int main()
{
	int n;
	int kase = 1;
	while (cin >> n && n)
	{
		node tmp;
		for (int i = 1; i <= n; ++i)
			Edge[i].clear();
		for (int i = 1; i <= n; ++i)
			cin >> x[i] >> y[i];
		for (int i = 1; i <= n; ++i)
			for (int j = 1; j <= n; ++j)
				if (i != j)
				{
					tmp.to = j, tmp.cost = len(x[i], x[j], y[i], y[j]);
					Edge[i].push_back(tmp);
				}
		dij(n);
		printf("Scenario #%d\n", kase++);
		printf("Frog Distance = %.3lf\n\n", dis[2]);
	}
	return 0;
}