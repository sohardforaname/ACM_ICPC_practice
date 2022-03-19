#include <bits/stdc++.h>
using namespace std;
const int N = 4e5 + 5;
struct edge
{
	int u, v, nxt;
	int tp;
};
edge e[N << 1];
int head[N];
int dfn[N], low[N], n, m, clk;
bool bri[N << 1];
int sel[N << 1];
int dcc[N], dcc_cnt, fver[N];
int dcc_num[N];
void tarjan(int u, int in_e)
{
	dfn[u] = low[u] = ++clk;
	for (int i = head[u]; i; i = e[i].nxt)
	{
		int v = e[i].v;
		if (!dfn[v])
		{
			tarjan(v, i);
			low[u] = min(low[u], low[v]);
			if (dfn[u] < low[v])
				bri[i] = bri[i ^ 1] = 1;
		}
		else if (i != (in_e ^ 1))
			low[u] = min(low[u], dfn[v]);
	}
}
void dfs(int u, int c)
{
	dcc[u] = c;
	++dcc_num[c];
	if (!fver[c])
		fver[c] = u;
	for (int i = head[u]; i; i = e[i].nxt)
	{
		int v = e[i].v;
		if (bri[i])
			continue;
		if (sel[i] == -1)
			sel[i] = sel[i ^ 1] = e[i].tp;
		if (dcc[v] == dcc[u])
			continue;
		dfs(v, c);
	}
}
bool vis[N];
void dfs2(int u)
{
	vis[u] = 1;
	for (int i = head[u]; i; i = e[i].nxt)
	{
		int v = e[i].v;
		if (vis[v])
			continue;
		if (bri[i] && sel[i] == -1)
			sel[i] = sel[i ^ 1] = e[i ^ 1].tp;
		dfs2(v);
	}
}
int tot;
void add(int u, int v, int tp)
{
	e[++tot].v = v, e[tot].u = u;
	e[tot].nxt = head[u], head[u] = tot;
	e[tot].tp = tp;
}
int main()
{
	memset(sel, -1, sizeof(sel));
	int u, v;
	scanf("%d%d", &n, &m);
	tot = 1;
	for (int i = 1; i <= m; ++i)
	{
		scanf("%d%d", &u, &v);
		add(u, v, 0);
		add(v, u, 1);
	}
	for (int i = 1; i <= n; ++i)
		if (!dfn[i])
			tarjan(i, 0);
	for (int i = 1; i <= n; ++i)
		if (!dcc[i])
			dfs(i, ++dcc_cnt);
	int maxn = 0, maxpos = 0;
	for (int i = 1; i <= dcc_cnt; ++i)
		if (maxn < dcc_num[i])
			maxn = dcc_num[i], maxpos = i;
	dfs2(fver[maxpos]);
	printf("%d\n", maxn);
	for (int i = 2; i <= (m << 1) + 1; i += 2)
	{
		if (sel[i] == 0)
			printf("%d %d\n", e[i].u, e[i].v);
		else if (sel[i] == 1)
			printf("%d %d\n", e[i].v, e[i].u);
	}
	return 0;
}