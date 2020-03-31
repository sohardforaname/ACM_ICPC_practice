#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;
struct node
{
	int to, cost;
	bool operator <(const node &a)const
	{
		return this->cost > a.cost;
	}
};
vector<node>Edge[10005];
int vis[10005], dis[10005];
void dij(int n)
{
	priority_queue<node>que;
	que.push(node{ 1,0 });
	memset(dis, 0x3f3f3f3f, sizeof(dis));
	memset(vis, 0, sizeof(vis));
	dis[1] = 0;
	while (!que.empty())
	{
		int u = que.top().to;
		que.pop();
		if (vis[u])
			continue;
		vis[u] = 1;
		for (int i = 0; i < Edge[u].size(); ++i)
		{
			int v = Edge[u][i].to;
			if (!vis[v] && dis[u] + Edge[u][i].cost < dis[v])
			{
				dis[v] = dis[u] + Edge[u][i].cost;
				que.push(node{ v,dis[v] });
			}
		}
	}
	cout << dis[n] << endl;
}
int main()
{
	int n, m, a, b, c;
	cin >> n >> m;
	for (int i = 0; i < n; ++i)
	{
		cin >> a >> b >> c;
		Edge[a].push_back(node{ b,c });
		Edge[b].push_back(node{ a,c });
	}
	dij(m);
	return 0;
}