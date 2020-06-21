#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;
int vis[105], dis[105];
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
vector<node> E[105];
void dij(int n)
{
	memset(vis, 0, sizeof(vis));
	memset(dis, 0x3f3f3f, sizeof(dis));
	priority_queue<node> que;
	dis[1] = 0;
	que.push(node(1, dis[1]));
	while (!que.empty())
	{
		int u = que.top().to;
		que.pop();
		if (vis[u])
			continue;
		vis[u] = 1;
		for (int i = 0; i < E[u].size(); ++i)
		{
			node tmp = E[u][i];
			if (dis[tmp.to] > dis[u] + tmp.w)
			{
				dis[tmp.to] = dis[u] + tmp.w;
				que.push(node(tmp.to, dis[tmp.to]));
			}
		}
	}
	cout << *max_element(dis + 2, dis + n + 1) << endl;
}
int stoi(string &str)
{
	int ans = 0;
	for (int i = 0; i < str.size(); ++i)
		ans = ans * 10 + str[i] - '0';
	return ans;
}
int main()
{
	int n, a;
	string tmp;
	cin >> n;
	for (int i = 2; i <= n; ++i)
		for (int j = 1; j < i; ++j)
		{
			cin >> tmp;
			if (tmp != "x")
				a = stoi(tmp);
			else
				a = 0x3f3f3f;
			E[i].push_back(node(j, a));
			E[j].push_back(node(i, a));
		}
	dij(n);
	return 0;
}