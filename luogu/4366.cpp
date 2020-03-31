#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;
int vis[100005], dis[100005];
struct node
{
	int to, cost;
	bool operator < (const node &a)const
	{
		return this->to > a.to;
	}
};
vector<node>Edge[100005];
void dijkstra(int i, int j)
{
	memset(vis, 0, sizeof(vis));
	memset(dis, 0x3f3f3f3f, sizeof(dis));
	dis[i] = 0;
	priority_queue<node>que;
	que.push(node{ i,dis[i] });
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
			if (!vis[i] && dis[v] > dis[u] + Edge[u][i].cost)
			{
				dis[v] = dis[u] + Edge[u][i].cost;
				que.push(node{ v,dis[v] });
			}
		}
	}
	cout << dis[j] << endl;
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, m, c, a, b;
	cin >> n >> m >> c;
	for (int i = 0; i < m; ++i)
	{
		cin >> a >> b;
		
	}
}