#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 5;
vector<int>G[MAXN];
bool vis[MAXN];
int v = 0;
void dfs(int fa, int u)
{
	vis[u] = 1;
	++v;
	for (auto i : G[u])
		if (i != fa && !vis[i])
			dfs(u, i);
}
int main()
{
	int n, m;
	scanf("%d%d", &n, &m);
	int a, b;
	for (int i = 1; i <= m; ++i)
	{
		scanf("%d%d", &a, &b);
		G[a].push_back(b);
		G[b].push_back(a);
	}
	if (n != m)
		return printf("NO\n"), 0;
	dfs(0, 1);
	if (v == n)
		return printf("FHTAGN!\n"), 0;
	else
		return printf("NO\n"), 0;
}