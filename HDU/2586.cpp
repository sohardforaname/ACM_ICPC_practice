#include <bits/stdc++.h>
using namespace std;
struct edge
{
	int v, w;
	edge(int a, int b)
	{
		v = a, w = b;
	}
	edge() {}
};
vector<edge>E[40005], Q[40005];
long long dis[40005], ans[40005];
int f[40005], in[40005];
bool vis[40005];
void dfs(int u)
{
	for (auto i : E[u])
	{
		dis[i.v] = dis[u] + i.w;
		dfs(i.v);
	}
}
int find(int i)
{
	return i == f[i] ? i : f[i] = find(f[i]);
}
void LCA(int u)
{
	for (auto i : E[u])
	{
		LCA(i.v);
		f[find(i.v)] = u;
	}
	vis[u] = 1;
	for (auto i : Q[u])
		if (vis[i.v] && !ans[i.w])
			ans[i.w] = dis[i.v] + dis[u] - 2 * dis[find(i.v)];
}
void init(int n, int m)
{
	for (int i = 1; i <= n; ++i)
	{
		E[i].clear();
		Q[i].clear();
		vis[i] = 0;
		dis[i] = 0;
		f[i] = i;
		in[i] = 0;
	}
	for (int i = 1; i <= m; ++i)
		ans[i] = 0;
}
int main()
{
	int T;
	cin >> T;
	while (T--)
	{
		int n, m, a, b, c;
		cin >> n >> m;
		init(n, m);
		for (int i = 0; i < n - 1; ++i)
		{
			cin >> a >> b >> c;
			E[a].push_back(edge(b, c));
			++in[b];
		}
		for (int i = 1; i <= m; ++i)
		{
			cin >> a >> b;
			Q[a].push_back(edge(b, i));
			Q[b].push_back(edge(a, i));
		}
		int rt;
		for (int i = 1; i <= n; ++i)
			if (in[i] == 0)
				rt = i;
		dfs(rt);
		LCA(rt);
		for (int i = 1; i <= m; ++i)
			cout << ans[i] << endl;
	}
	return 0;
}