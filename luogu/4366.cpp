#include "../base.h"

const int N = 1e5 + 5;
bool multi = 0;

struct edge
{
	int to;
	ll w;
	bool operator<(const edge &e) const
	{
		return w > e.w;
	}
};
vector<edge> G[N];
int n, m;
ll dis[N];
bool vis[N];
void dijkstra(int s)
{
	fill(dis, dis + n + 1, 1e18);
	fill(vis, vis + n + 1, 0);
	dis[s] = 0;
	priority_queue<edge> q;
	q.push({s, 0});
	while (q.size())
	{
		int u = q.top().to;
		q.pop();
		if (vis[u])
			continue;
		vis[u] = 1;
		for (auto i : G[u])
			if (dis[i.to] > dis[u] + i.w)
			{
				dis[i.to] = dis[u] + i.w;
				q.push({i.to, dis[i.to]});
			}
	}
}
void solve()
{
	ll c;
	io(n, m, c);
	for (int i = 1; i <= m; ++i)
	{
		int u, v, w;
		io(u, v, w);
		G[u].push_back({v, w});
	}
	int s, t;
	io(s, t);
	for (int i = 0; i <= n; ++i)
		for (int j = 0; j < 18; ++j)
			if (i + (1 << j) <= n)
			{
				ll cst = (i ^ (i + (1 << j))) * c;
				G[i].push_back({i + (1 << j), cst});
				G[i + (1 << j)].push_back({i, cst});
			}
	dijkstra(s);
	io(dis[t], '\n');
}
int main()
{
	int t;
	if (multi)
		io(t);
	else
		t = 1;
	while (t--)
		solve();
	return 0;
}