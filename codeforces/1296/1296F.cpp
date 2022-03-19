#include <bits/stdc++.h>
using namespace std;
const int N = 5e3 + 5;
const int M = 1e6 + 1;
vector<pair<int, int> >G[N];
int dep[N], w[N], f[N];
void dfs(int u, int fa)
{
	f[u] = fa;
	dep[u] = dep[fa] + 1;
	for (auto i : G[u])
		if (!dep[i.first])
			dfs(i.first, u);
}
void setval(int u, int v, int val)
{
	if (dep[u] < dep[v])
		swap(u, v);
	while (dep[u] > dep[v])
	{
		if (w[u] == M)
			w[u] = val;
		u = f[u];
	}
	while (u != v)
	{
		if (w[u] == M)
			w[u] = val;
		if (w[v] == M)
			w[v] = val;
		u = f[u], v = f[v];
	}
}
bool chk(int u, int v, int val)
{
	if (dep[u] < dep[v])
		swap(u, v);
	int minn = 1e6 + 1;
	while (dep[u] > dep[v])
	{
		minn = min(minn, w[u]);
		u = f[u];
	}
	while (u != v)
	{
		minn = min(minn, min(w[u], w[v]));
		u = f[u], v = f[v];
	}
	return minn == val;
}
int ans[N];
void get_ans(int u, int fa)
{
	for (auto i : G[u])
	{
		if (i.first == fa)
			continue;
		ans[i.second] = w[i.first];
		get_ans(i.first, u);
	}
}
struct query
{
	int u, v, val;
}q[N];
int main()
{
	int n, u, v;
	scanf("%d", &n);
	for (int i = 1; i < n; ++i)
	{
		scanf("%d%d", &u, &v);
		G[u].push_back({ v,i });
		G[v].push_back({ u,i });
	}
	for (int i = 2; i <= n; ++i)
		w[i] = (int)1e6 + 1;
	dfs(1, 0);
	int m;
	scanf("%d", &m);
	bool f = 1;
	for (int i = 1; i <= m; ++i)
		scanf("%d%d%d", &q[i].u, &q[i].v, &q[i].val);
	sort(q + 1, q + m + 1, [](query& a, query& b)->bool {return a.val > b.val; });
	for (int i = 1; i <= m; ++i)
		setval(q[i].u, q[i].v, q[i].val);
	for (int i = 1; i <= m; ++i)
		if (!chk(q[i].u, q[i].v, q[i].val))
			f = 0;
	if (!f)
		printf("-1\n");
	else
	{
		get_ans(1, 0);
		for (int i = 1; i < n; ++i)
			printf("%d%c", ans[i] == M ? (int)1e6 : ans[i], " \n"[i == n]);
	}
	return 0;
}
