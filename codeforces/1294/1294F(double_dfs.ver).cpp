#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
int pre[N], dis[N];
bool vis[N];
vector<int>G[N];
void dfs(int u)
{
	vis[u] = 1;
	for (auto i : G[u])
	{
		if (vis[i])
			continue;
		pre[i] = u;
		dis[i] = dis[u] + 1;
		dfs(i);
	}
}
int bfs(int n, int& z)
{
	z = 0;
	queue<int>q;
	memset(dis, 0, sizeof(dis[0]) * (n + 1));
	for (int i = 1; i <= n; ++i)
		if (vis[i])
			q.push(i);
	int ans = 0;
	while (!q.empty())
	{
		int cur = q.front();
		q.pop();
		for (auto i : G[cur])
			if (!dis[i] && !vis[i])
			{
				dis[i] = dis[cur] + 1;
				if (ans < dis[i])
					ans = dis[i], z = i;
				q.push(i);
			}
	}
	return ans;
}
int cal(int& x, int& y, int& z, int n)
{
	x = 0, y = 0;
	int ans = 0;
	dfs(1);
	int maxn = 0;
	for (int i = 1; i <= n; ++i)
		if (dis[i] > maxn)
			maxn = dis[i], x = i;
	dis[x] = pre[x] = 0;
	memset(vis, 0, sizeof(vis[0]) * (n + 1));
	dfs(x);
	maxn = 0;
	for (int i = 1; i <= n; ++i)
		if (dis[i] > maxn)
			maxn = dis[i], y = i;
	ans += maxn;
	int pos = y;
	memset(vis, 0, sizeof(vis[0]) * (n + 1));
	while (pos)
	{
		vis[pos] = 1;
		pos = pre[pos];
	}
	ans += bfs(n, z);
	if (!z)
		for (int i = 1; i <= n; ++i)
			if (i != x && i != y)
				return (z = i), ans;
	return ans;
}
int main()
{
	int n;
	scanf("%d", &n);
	int a, b;
	for (int i = 1; i < n; ++i)
	{
		scanf("%d%d", &a, &b);
		G[a].push_back(b);
		G[b].push_back(a);
	}
	int x, y, z;
	int ans = cal(x, y, z, n);
	printf("%d\n%d %d %d\n", ans, x, y, z);
	return 0;
}