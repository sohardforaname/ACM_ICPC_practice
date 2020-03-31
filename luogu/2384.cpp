#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
int vis[1005];
long long dis[1005];
struct  node
{
	int to;
	long long cost;
	bool operator <(const node &a)const
	{
		return a.to < this->to;
	}
};
vector<node>Edge[1005];
void dijkstra(int n)
{
	priority_queue<node>que;
	memset(dis, 0x3f3f3f3f3f3f3f3f, sizeof(dis));
	memset(vis, 0, sizeof(vis));
	dis[1] = 1;
	que.push(node{ 1,dis[1] });
	while (!que.empty())
	{
		int u = que.top().to;
		que.pop();
		if (vis[u])
			continue;
		vis[u] = 0;
		for (int i = 0; i < Edge[u].size(); ++i)
		{
			int v = Edge[u][i].to;
			if (!vis[i] && dis[v] > dis[u] * Edge[u][i].cost)
			{
				dis[v] = dis[u] * Edge[u][i].cost;
				que.push(node{ v, dis[v] });
			}
		}
	}
	cout << dis[n] % 9987 << endl;
}
int main()
{
	int n, m, a, b, c;
	cin >> n >> m;
	for (int i = 0; i < m; ++i)
	{
		cin >> a >> b >> c;
		Edge[a].push_back(node{ b,c });
	}
	dijkstra(n);
	return 0;
}