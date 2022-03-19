#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
int dep[1000005], vis[1000005], cnt[1000005];
vector<int>Edge[1000005];
void bfs(int n)
{
	queue<int>que;
	que.push(1);
	dep[1] = 1, cnt[1] = 1, vis[1] = 1;
	while (!que.empty())
	{
		int u = que.front();
		que.pop();
		for (auto v : Edge[u])
		{
			if (!vis[v])
			{
				dep[v] = dep[u] + 1;
				vis[v] = 1;
				que.push(v);
			}
			if (dep[v] == dep[u] + 1)
				cnt[v] = (cnt[v] + cnt[u]) % 100003;
		}
	}
	for (int i = 1; i <= n; ++i)
		cout << cnt[i] << endl;
}
int main()
{
	int n, m, a, b;
	cin >> n >> m;
	for (int i = 0; i < m; ++i)
	{
		cin >> a >> b;
		if (a != b)
		{
			Edge[a].push_back(b);
			Edge[b].push_back(a);
		}
	}
	bfs(n);
	return 0;
}