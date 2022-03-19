#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;
struct node
{
	int to, cost;
	node(int a, int b)
	{
		to = a, cost = b;
	}
	bool operator<(const node &a) const
	{
		return this->cost > a.cost;
	}
};
int vis[1005], dis[1005];
vector<node> E[1005];
void dij(int n, int s)
{
	queue<node> que;
	memset(dis, 0, sizeof(dis));
	for (int i = 0; i < E[1].size(); ++i)
	{
		dis[E[1][i].to] = E[1][i].cost;
		que.push(node(E[1][i].to, E[1][i].cost));
	}
	memset(vis, 0, sizeof(vis));
	dis[1] = 0x3f3f3f3f;
	vis[1] = 1;
	while (!que.empty())
	{
		int u = que.front().to;
		que.pop();
		//if (vis[u])
		//continue;
		//vis[u] = 1;
		for (int i = 0; i < E[u].size(); ++i)
		{
			int v = E[u][i].to, cost = E[u][i].cost;
			if (min(dis[u], cost) > dis[v])
			{
				dis[v] = min(dis[u], cost);
				//if (!vis[v])
				que.push(node(v, dis[v]));
			}
		}
	}
	cout << "Scenario #" << s << ":" << endl;
	cout << dis[n] << endl
		 << endl;
}
int main()
{
	int s, n, m, a, b, c;
	cin >> s;
	for (int j = 1; j <= s; ++j)
	{
		cin >> n >> m;
		for (int i = 1; i <= n; ++i)
			E[i].clear();
		for (int i = 0; i < m; ++i)
		{
			cin >> a >> b >> c;
			E[a].push_back(node(b, c));
			E[b].push_back(node(a, c));
		}
		dij(n, j);
	}
	return 0;
}