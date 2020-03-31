#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 5;
const int MAXM = 2e5 + 5;
int dfn[MAXN], low[MAXN], dfn_c;
int head[MAXM], nxt[MAXM], ver[MAXM], tot;
bool bri[MAXM];
int ans;
void add(int u, int v)//图上加边
{
	ver[++tot] = v;
	nxt[tot] = head[u];
	head[u] = tot;
}
void tarjan(int u, int in_edge)//求割边
{
	dfn[u] = low[u] = ++dfn_c;
	for (int i = head[u]; i; i = nxt[i])
	{
		int v = ver[i];
		if (!dfn[v])
		{
			tarjan(v, i);
			low[u] = min(low[u], low[v]);
			if (low[v] > dfn[u])
				bri[i] = bri[i ^ 1] = 1, ++ans;
		}
		else if (i != (in_edge ^ 1))
			low[u] = min(low[u], dfn[v]);
	}
}

int hc[MAXM], nc[MAXM], vc[MAXN];
int tc;
int dcc[MAXN], dcc_cnt;
void add_c(int x, int y)//树上加边
{
	vc[++tc] = y, nc[tc] = hc[x], hc[x] = tc;
}
void dfs(int u)//缩点
{
	dcc[u] = dcc_cnt;
	for (int i = head[u]; i; i = nxt[i])
	{
		int v = ver[i];
		if (bri[i] || dcc[v])
			continue;
		dfs(v);
	}
}

int f[MAXN][20];

int fa[MAXN];
int find(int x)
{
	return x == fa[x] ? x : fa[x] = find(fa[x]);
}
int join(int x, int y)
{
	int fx = find(x), fy = find(y);
	if (fx != fy)
		fa[fx] = fy;
	find(x);
}

void init(int n, int m)
{
	for (int i = 1; i <= n; ++i)
	{
		dfn[i] = low[i] = head[i] = 0;
		fa[i] = i;
	}
	for (int i = 1; i <= m << 1; ++i)
		ver[i] = nxt[i] = 0;
	dfn_c = tot = 0;
}

int main()
{
	int n, m;
	while (scanf("%d%d", &n, &m) && n + m)
	{
		init(n, m);
		int u, v;
		while(m--)
		{
			scanf("%d%d", &u, &v);
			add(u, v);
			add(v, u);
		}
		for (int i = 1; i <= n; ++i)
			if (!dfn[i])
				tarjan(i, 0);
	}
}