#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;
struct node
{
	int to, w;
	node(int a, int b)
	{
		to = a, w = b;
	}
	bool operator<(const node &a) const
	{
		return this->w > a.w;
	}
};
vector<node> E[30];
int vis[30], dis[30];
int prim(int n)
{
	memset(vis, 0, sizeof(vis));
	memset(dis, 0x3f3f3f3f, sizeof(dis));
	dis[1] = 0;
	priority_queue<node> que;
	que.push(node(1, dis[1]));
	int sum = 0;
	while (!que.empty())
	{
		node to = que.top(); //dis较小的点出队
		int u = to.to;
		que.pop();
		if (vis[u])
			continue;
		vis[u] = 1;
		sum += to.w; //加上边
		for (int i = 0; i < E[u].size(); ++i)
		{
			int v = E[u][i].to;
			if (dis[v] > E[u][i].w)
			{
				dis[v] = E[u][i].w; //维护dis[v]是已经加入最小生成树点集的点的最小距离，且必定是边。
				que.push(node(v, dis[v]));
			}
		}
	}
	return sum;
}
int main()
{
	int n, a, c;
	char t, b;
	while (cin >> n && n)
	{
		for (int i = 1; i <= n; ++i)
			E[i].clear();
		for (int i = 0; i < n - 1; ++i)
		{
			cin >> t >> a;
			for (int j = 0; j < a; ++j)
			{
				cin >> b >> c;
				E[t - 'A' + 1].push_back(node(b - 'A' + 1, c));
				E[b - 'A' + 1].push_back(node(t - 'A' + 1, c));
			}
		}
		cout << prim(n) << endl;
	}
	return 0;
}