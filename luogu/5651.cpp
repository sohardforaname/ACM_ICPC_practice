#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 5;
struct node
{
	int v, w;
	node() {};
	node(int _v, int _w) :v(_v), w(_w) {}
};
vector<node>G[MAXN];
bool vis[MAXN];
int dis[MAXN];
void dfs(int f, int u, int val)
{
	vis[u] = 1;
	dis[u] = dis[f] ^ val;
	for (int i = 0; i < G[u].size(); ++i)
	{
		int v = G[u][i].v;
		if (v != f && !vis[v])
			dfs(u, v, G[u][i].w);
	}
}
int main()
{
	int n, m, q;
	scanf("%d%d%d", &n, &m, &q);
	int a, b, c;
	for (int i = 1; i <= m; ++i)
	{
		scanf("%d%d%d", &a, &b, &c);
		G[a].push_back(node(b, c));
		G[b].push_back(node(a, c));
	}
	dfs(0, 1, 0);
	for (int i = 1; i <= q; ++i)
	{
		scanf("%d%d", &a, &b);
		printf("%d\n", dis[a] ^ dis[b]);
	}
	return 0;
}
