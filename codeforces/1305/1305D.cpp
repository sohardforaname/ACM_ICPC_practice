#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 5;
set<int>G[N];
bool vis[N];
queue<int>que;
int query(int u, int v)
{
	int lca = 0;
	printf("? %d %d\n", u, v);
	fflush(stdout);
	scanf("%d", &lca);
	if (u == lca || v == lca)
	{
		printf("! %d\n", lca);
		fflush(stdout);
		exit(0);
	}
	return lca;
}
int main()
{
	int n, u, v;
	scanf("%d", &n);
	for (int i = 1; i < n; ++i)
	{
		scanf("%d%d", &u, &v);
		G[u].insert(v);
		G[v].insert(u);
	}
	for (int i = 1; i <= n; ++i)
		if (G[i].size() == 1)
			que.push(i), vis[i] = 1;
	while (que.size() >= 2)
	{
		int u = que.front();
		que.pop();
		int v = que.front();
		que.pop();
		int lca = query(u, v);
		for (auto i : G[u])
		{
			G[i].erase(u);
			if (!vis[i] && G[i].size() == 1)
				que.push(i), vis[i] = 1;
		}
		for (auto i : G[v])
		{
			G[i].erase(v);
			if (!vis[i] && G[i].size() == 1)
				que.push(i), vis[i] = 1;
		}
	}
	printf("! %d\n", que.front());
	fflush(stdout);
	return 0;
}