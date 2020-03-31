#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 5;
typedef long long ll;
pair<double, double>p[N];
int n;
double w;
struct edge
{
	int to;
	double w;
	bool operator <(const edge& a)const
	{
		return w > a.w;
	}
};
vector<edge>G[N];
double len(pair<double, double>& a, pair<double, double>& b)
{
	return sqrt((a.first - b.first) * (a.first - b.first) +
		(a.second - b.second) * (a.second - b.second));
}
double dist[N], diss[N];
bool vis[N];
void dijkstra(int s, double* dis)
{
	priority_queue<edge>q;
	for (int i = 0; i <= n + 1; ++i)
		dis[i] = 0x3f3f3f3f3f3f3f3f;
	memset(vis, 0, sizeof(vis));
	q.push({ s,0 });
	dis[s] = 0;
	while (q.size())
	{
		edge cur = q.top();
		q.pop();
		if (vis[cur.to])
			continue;
		vis[cur.to] = 1;
		for (auto i : G[cur.to])
			if (max(dis[cur.to], i.w) < dis[i.to])
			{
				dis[i.to] = max(dis[cur.to], i.w);
				q.push({ i.to,dis[i.to] });
			}
	}
}
void init1()
{
	for (int i = 0; i <= n + 1; ++i)
		G[i].clear();
	for (int i = 1; i <= n; ++i)
	{
		G[0].push_back({ i,p[i].first });
		G[i].push_back({ n + 1,w - p[i].first });
	}
	for (int i = 1; i <= n; ++i)
		for (int j = i + 1; j <= n; ++j)
		{
			double d = len(p[i], p[j]);
			G[i].push_back({ j,d });
			G[j].push_back({ i,d });
		}
}
void init2()
{
	for (int i = 0; i <= n + 1; ++i)
		G[i].clear();
	for (int i = 1; i <= n; ++i)
	{
		G[n + 1].push_back({ i,w - p[i].first });
		G[i].push_back({ 0,p[i].first });
	}
	for (int i = 1; i <= n; ++i)
		for (int j = i + 1; j <= n; ++j)
		{
			double d = len(p[i], p[j]);
			G[i].push_back({ j,d });
			G[j].push_back({ i,d });
		}
}
int main()
{
#ifndef _Aya
	freopen("froggy.in", "r", stdin);
	freopen("froggy.out", "w", stdout);
#endif
	scanf("%lf%d", &w, &n);
	for (int i = 1; i <= n; ++i)
		scanf("%lf%lf", &p[i].first, &p[i].second);
	init1();
	dijkstra(0, diss);
	init2();
	dijkstra(n + 1, dist);
	double maxn = 0x3f3f3f3f3f3f3f3f;
	double ansx = 0, ansy = 0;
	for (int i = 0; i <= n + 1; ++i)
		for (int j = 0; j <= n + 1; ++j)
		{
			double tmp;
			if (i == j)
				continue;
			if (i == 0 && j == n + 1)
				tmp = w;
			else if (i == 0)
				tmp = p[j].first;
			else if (j == n + 1)
				tmp = w - p[i].first;
			else
				tmp = len(p[i], p[j]);
			if (maxn > max(max(diss[i], tmp / 2), max(tmp / 2, dist[j])))
			{
				maxn = max(max(diss[i], tmp / 2), max(tmp / 2, dist[j]));
				if (i == 0 && j != n + 1)
					ansx = p[j].first / 2, ansy = p[j].second;
				else if (i != 0 && j == n + 1)
					ansx = (p[i].first + w) / 2, ansy = p[i].second;
				else if (i == 0 && j == n + 1)
					ansx = w / 2, ansy = 0;
				else
					ansx = (p[i].first + p[j].first) / 2, ansy = (p[i].second + p[j].second) / 2;
			}
		}
	printf("%lf %lf\n", ansx, ansy);
	return 0;
}
/*
10 7
2 2
2 4
5 1
5 3
8 2
7 5
9 4
*/