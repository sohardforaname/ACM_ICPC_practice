#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2e5 + 5;
const int INF = 0x3f3f3f3f;
int a[MAXN], b[MAXN], l[MAXN], r[MAXN];
queue<int>Q;
vector<int>G[MAXN];
int dis[MAXN];
bool vis[MAXN];
int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i)
		scanf("%d", &a[i]);
	for (int i = 1; i <= n; ++i)
		b[i] = a[i] & 1;
	memset(dis, 0x3f, sizeof(dis));
	int x;
	for (int i = 1; i <= n; ++i)
	{
		x = i + a[i];
		if (x >= 1 && x <= n)
		{
			G[x].push_back(i);
			l[i] = x;
		}
		else
			l[i] = -INF;
		x = i - a[i];
		if (x >= 1 && x <= n)
		{
			G[x].push_back(i);
			r[i] = x;
		}
		else
			r[i] = -INF;
	}
	for (int i = 1; i <= n; ++i)
	{
		if (l[i] > 0 && b[i] + b[l[i]] == 1)
			dis[i] = 1;
		else if (r[i] > 0 && b[i] + b[r[i]] == 1)
			dis[i] = 1;
	}
	for (int i = 1; i <= n; ++i)
		if (dis[i] == 1)
			Q.push(i);
	while (!Q.empty())
	{
		int u = Q.front();
		Q.pop();
		if (vis[u])
			continue;
		vis[u] = 1;
		for (auto i : G[u])
		{
			if (!vis[i])
			{
				dis[i] = min(dis[i], dis[u] + 1);
				Q.push(i);
			}
		}
	}
	for (int i = 1; i <= n; ++i)
		printf("%d%c", dis[i] < INF ? dis[i] : -1, i == n ? '\n' : ' ');
	return 0;
}