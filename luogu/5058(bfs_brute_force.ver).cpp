#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e2 + 5;
vector<int>G[MAXN];
bool vis[MAXN];
queue<int>Q;
int a, b;
bool bfs(int s)
{
	memset(vis, 0, sizeof(vis));
	Q.push(a);
	vis[a] = 1;
	while (!Q.empty())
	{
		int u = Q.front();
		Q.pop();
		vis[u] = 1;
		for (auto i : G[u])
			if (!vis[i] && i != s)
				Q.push(i);
	}
	return vis[a] == vis[b];
}
int main()
{
	int n;
	int u, v;
	scanf("%d", &n);
	while (scanf("%d%d", &v, &u) && u + v)
	{
		G[u].push_back(v);
		G[v].push_back(u);
	}
	scanf("%d%d", &a, &b);
	int f = 0;
	for (int i = 1; i <= n; ++i)
		if (i != a && i != b && !bfs(i))
		{
			f = i;
			break;
		}
	if (!f)
		printf("No solution\n");
	else
		printf("%d\n", f);
	return 0;
}