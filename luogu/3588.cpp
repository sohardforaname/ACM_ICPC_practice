#include <bits/stdc++.h>
using namespace std;
const int MAXN = (1e6 + 5);
struct node
{
	int l, r;
};
node tr[MAXN];
struct edge
{
	int to, w;
	edge() {}
	edge(int _to, int _w) :to(_to), w(_w) {}
	bool operator<(const edge& a)const
	{
		return w > a.w;
	}
};
vector<edge>G[MAXN];
int cnt;
int deg[MAXN];
void build(int& rt, int l, int r)
{
	if (l == r)
	{
		rt = l;
		return;
	}
	rt = ++cnt;
	int m = (l + r) >> 1;
	build(tr[rt].l, l, m);
	build(tr[rt].r, m + 1, r);
	G[tr[rt].l].push_back(edge(rt, 0));
	G[tr[rt].r].push_back(edge(rt, 0));
	deg[rt] += 2;
}
void update(int rt, int l, int r, int ql, int qr, int v)
{
	if (l > r)
		return;
	if (l <= ql && r >= qr)
	{
		G[rt].push_back(edge(v, 1));
		++deg[v];
		return;
	}
	int m = (ql + qr) >> 1;
	if (l <= m)
		update(tr[rt].l, l, r, ql, m, v);
	if (r > m)
		update(tr[rt].r, l, r, m + 1, qr, v);
}
queue<int>Q;
long long dis[MAXN];
int val[MAXN];
bool vis[MAXN];
bool toposort()
{
	for (int i = 1; i <= cnt; ++i)
		if (!deg[i])
		{
			Q.push(i);
			dis[i] = val[i] ? val[i] : 1;
		}
	while (Q.size())
	{
		int u = Q.front();
		Q.pop();
		vis[u] = 1;
		for (auto i : G[u])
		{
			int v = i.to, w = i.w;
			--deg[v];
			dis[v] = max(dis[v], dis[u] + w);
			if (!vis[v] && !deg[v])
			{
				if (val[v])
				{
					if (dis[v] > val[v])
						return false;
					dis[v] = val[v];
				}
				Q.push(v);
			}
		}
	}
	for (int i = 1; i <= cnt; ++i)
		if (!vis[i] || dis[i] > 1e9)
			return false;
	return true;
}
int rt;
int main()
{
	int n, s, m;
	scanf("%d%d%d", &n, &s, &m);
	cnt = n;
	int a, p;
	while (s--)
	{
		scanf("%d%d", &a, &p);
		val[a] = p;
	}
	int las, x, k, l, r;
	build(rt, 1, n);
	while (m--)
	{
		scanf("%d%d%d", &l, &r, &k);
		las = l;
		++cnt;
		while (k--)
		{
			scanf("%d", &x);
			update(rt, las, x - 1, 1, n, cnt);
			G[cnt].push_back(edge(x, 0));
			++deg[x];
			las = x + 1;
		}
		update(rt, las, r, 1, n, cnt);
	}
	if (!toposort())
		printf("NIE\n");
	else
	{
		printf("TAK\n");
		for (int i = 1; i <= n; ++i)
			printf("%lld%c", dis[i], i == n ? '\n' : ' ');
	}
	return 0;
}	