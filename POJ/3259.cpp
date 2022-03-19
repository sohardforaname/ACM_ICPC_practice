#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;
int dis[505], vis[505], inque[505];
struct node
{
	int to, w;
	node(int a, int b)
	{
		to = a, w = b;
	}
};
vector<node>E[505];
bool spfa(int s, int n)
{
	memset(vis, 0, sizeof(vis));
	memset(dis, 0x3f3f3f3f, sizeof(dis));
	memset(inque, 0, sizeof(inque));
	dis[s] = 0;
	vis[s] = 1;
	++inque[s];
	queue<int>que;
	que.push(1);
	while (!que.empty())
	{
		int u = que.front();
		que.pop();
		vis[u] = 0;
		for (int i = 0; i < E[u].size(); ++i)
		{
			int v = E[u][i].to;
			if (dis[v] > dis[u] + E[u][i].w)
			{
				dis[v] = dis[u] + E[u][i].w;
				if (!vis[v])
				{
					que.push(v);
					vis[v] = 1;
					++inque[v];
				}
				if (inque[v] > n)
					return 1;
			}
		}
	}
	return 0;
}
int main()
{
	int v;
	cin >> v;
	while (v--)
	{
		int n, m, w, a, b, c;
		cin >> n >> m >> w;
		for (int i = 1; i <= n; ++i)
			E[i].clear();
		for (int i = 0; i < m; ++i)
		{
			cin >> a >> b >> c;
			E[a].push_back(node(b, c));
			E[b].push_back(node(a, c));
		}
		for (int i = 0; i < w; ++i)
		{
			cin >> a >> b >> c;
			E[a].push_back(node(b, -c));
		}
		if (spfa(1, n))
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
	return 0;
}