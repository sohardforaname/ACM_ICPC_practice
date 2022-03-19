#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
int dis[55], vis[55];
struct node
{
	int to, w;
	node(int a, int b)
	{
		to = a, w = b;
	}
	bool operator <(const node& a)const
	{
		return this->w > a.w;
	}
};
vector<node>E[55];
int prim(int n)
{
	memset(dis, 0x3f3f3f3f, sizeof(dis));
	memset(vis, 0, sizeof(vis));
	dis[1] = 0;
	priority_queue<node>que;
	que.push(node(1, dis[1]));
	int sum = 0;
	while (!que.empty())
	{
		int u = que.top().to, w = que.top().w;
		que.pop();
		if (vis[u])
			continue;
		vis[u] = 1;
		sum += w;
		for (int i = 0; i < E[u].size(); ++i)
		{
			int v = E[u][i].to, w = E[u][i].w;
			if (dis[v] > w)
			{
				dis[v] = w;
				que.push(node(v, dis[v]));
			}
		}
	}
	return sum;
}
int main()
{
	int n, m, a, b, c;
	while (cin >> n && n)
	{
		for (int i = 1; i <= n; ++i)
			E[i].clear();
		cin >> m;
		for (int i = 0; i < m; ++i)
		{
			cin >> a >> b >> c;
			E[a].push_back(node(b, c));
			E[b].push_back(node(a, c));
		}
		cout << prim(n) << endl;
	}
	return 0;
}