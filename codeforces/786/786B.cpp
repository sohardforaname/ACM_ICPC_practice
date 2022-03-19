#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN = 5e5 + 5;
struct node
{
	int l, r;
};
node tr[MAXN];
struct edge
{
	int to;
	ll w;
	edge() {}
	edge(int _to, ll _w) :to(_to), w(_w) {}
	bool operator<(const edge& a)const
	{
		return w > a.w;
	}
};
vector<edge>G[MAXN];
int cnt = 0;
void buildout(int& rt, int l, int r)
{
	if (l == r)
	{
		rt = l;
		return;
	}
	rt = ++cnt;
	int m = (l + r) >> 1;
	buildout(tr[rt].l, l, m);
	buildout(tr[rt].r, m + 1, r);
	G[rt].push_back(edge(tr[rt].l, 0));
	G[rt].push_back(edge(tr[rt].r, 0));
}
void buildin(int& rt, int l, int r)
{
	if (l == r)
	{
		rt = l;
		return;
	}
	rt = ++cnt;
	int m = (l + r) >> 1;
	buildin(tr[rt].l, l, m);
	buildin(tr[rt].r, m + 1, r);
	G[tr[rt].l].push_back(edge(rt, 0));
	G[tr[rt].r].push_back(edge(rt, 0));
}
void update(int rt, int l, int r, int ql, int qr, int v, int w, int type)
{
	if (l <= ql && r >= qr)
	{
		type == 2 ? G[v].push_back(edge(rt, w)) : G[rt].push_back(edge(v, w));
		return;
	}
	int m = (ql + qr) >> 1;
	if (l <= m)
		update(tr[rt].l, l, r, ql, m, v, w, type);
	if (r > m)
		update(tr[rt].r, l, r, m + 1, qr, v, w, type);
}
const ll INF = 0x3f3f3f3f3f3f3f3f;
ll dis[MAXN];
bool vis[MAXN];
priority_queue<edge>Q;
void dijkstra(int s)
{
	memset(vis, 0, sizeof(vis));
	memset(dis, 0x3f, sizeof(dis));
	dis[s] = 0;
	Q.push(edge(s, dis[s]));
	while (Q.size())
	{
		auto u = Q.top();
		Q.pop();
		if (vis[u.to])
			continue;
		vis[u.to] = 1;
		for (auto i : G[u.to])
		{
			int v = i.to;
			if (!vis[v] && dis[v] > dis[u.to] + i.w)
			{
				dis[v] = dis[u.to] + i.w;
				Q.push(edge(v, dis[v]));
			}
		}
	}
}
int rt1, rt2;
int main()
{
	int n, m, s;
	scanf("%d%d%d", &n, &m, &s);
	cnt = n + 1;
	buildin(rt2, 1, n);//区间出去
	buildout(rt1, 1, n);//区间进来
	int op, u, v, l, r, w;
	while (m--)
	{
		scanf("%d", &op);
		if (op == 1)
		{
			scanf("%d%d%d", &u, &v, &w);
			G[u].push_back(edge(v, w));
		}
		else
		{
			scanf("%d%d%d%d", &v, &l, &r, &w);
			update(op == 2 ? rt1 : rt2, l, r, 1, n, v, w, op);
		}
	}
	dijkstra(s);
	for (int i = 1; i <= n; ++i)
		printf("%lld%c", dis[i] >= INF ? -1 : dis[i], i == n ? '\n' : ' ');
	return 0;
}