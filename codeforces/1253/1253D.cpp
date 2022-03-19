#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2e5 + 5;
vector<int>G[MAXN];
bool vis[MAXN];
pair<int, int>pvec[MAXN];
void dfs(int u, int& minn, int& maxn)
{
	vis[u] = 1;
	minn = min(minn, u);
	maxn = max(maxn, u);
	for (auto i : G[u])
		if (!vis[i])
			dfs(i, minn, maxn);
}
int main()
{
	int n, m, a, b;
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= m; ++i)
	{
		scanf("%d%d", &a, &b);
		G[a].push_back(b);
		G[b].push_back(a);
	}
	int top = 0;
	for (int i = 1; i <= n; ++i)
		if (!vis[i])
		{
			pvec[++top].first = n;
			dfs(i, pvec[top].first, pvec[top].second);
		}
	sort(pvec + 1, pvec + top + 1);
	int cnt = 0, maxn = 0;
	for (int i = 1; i <= top; ++i)
	{
		if (pvec[i].first < maxn)
			++cnt;
		maxn = max(maxn, pvec[i].second);
	}
	printf("%d\n", cnt);
	return 0;
}