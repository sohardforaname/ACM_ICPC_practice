#include <bits/stdc++.h>
using namespace std;
const int N = 2e2 + 5, M = 26;
set<int>G[M];
bool vis[M];
char s[N];
void dfs(int u, int f)
{
	if (vis[u])
		return;
	vis[u] = 1;
	putchar(u + 'a');
	for (auto i : G[u])
		dfs(i, u);
}
int solve()
{
	scanf("%s", s);
	memset(vis, 0, sizeof(vis));
	int len = strlen(s);
	if (len == 1)
		return printf("YES\nabcdefghijklmnopqrstuvwxyz\n"), 0;
	for (int i = 0; i < M; ++i)
	{
		G[i].clear();
		vis[i] = 0;
	}
	for (int i = 1; i < len; ++i)
	{
		G[s[i] - 'a'].insert(s[i - 1] - 'a');
		G[s[i - 1] - 'a'].insert(s[i] - 'a');
	}
	int cnt1 = 0, rt;
	for (int i = 0; i < M; ++i)
	{
		if (G[i].size() > 2)
			return printf("NO\n"), 0;
		else if (G[i].size() == 1)
			++cnt1, rt = i;
	}
	if (cnt1 != 2)
		return printf("NO\n"), 0;
	printf("YES\n");
	dfs(rt, -1);
	for (int i = 0; i < M; ++i)
		dfs(i, -1);
	return printf("\n"), 0;
}
int main()
{
	int t;
	scanf("%d", &t);
	while (t--)
		solve();
	return 0;
}
