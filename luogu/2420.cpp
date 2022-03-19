#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int sum[N], dep[N];
vector<pair<int, int> >G[N];
void dfs(int u, int f, int v)
{
	sum[u] = sum[f] ^ v;
	for (auto i : G[u])
		if (i.first != f)
			dfs(i.first, u, i.second);
}
int main()
{
	int n, m;
	scanf("%d", &n);
	int a, b, c;
	for (int i = 1; i < n; ++i)
	{
		scanf("%d%d%d", &a, &b, &c);
		G[a].push_back({ b,c });
		G[b].push_back({ a,c });
	}
	dfs(1, 0, 0);
	scanf("%d", &m);
	for (int i = 1; i <= m; ++i)
	{
		scanf("%d%d", &a, &b);
		printf("%d\n", sum[a] ^ sum[b]);
	}
	return 0;
}