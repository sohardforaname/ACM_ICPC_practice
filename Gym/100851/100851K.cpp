#include <bits/stdc++.h>
using namespace std;
const int N = 1.5e5 + 5;
vector<int>G[N];
vector<int>cpx;
int nxt[N], arr[N];
bool vis[N];
int n, m;
void failed()
{
	printf("There is no route, Karl!\n");
	exit(0);
}
void check()
{
	memset(arr, 0, sizeof(arr));
	for (int i = 1, x = 1; i <= n; ++i, x = nxt[x])
	{
		if (arr[x])//重复经过点
			return;
		arr[x] = 1;
	}
	for (int i = 1, x = 1; i <= n; ++i, x = nxt[x])
		printf("%d ", x);
	printf("1\n");
	exit(0);
}
void dfs(int pos)
{
	if (pos == cpx.size())//选完了
	{
		check();
		return;
	}
	int x = cpx[pos];
	for (auto i : G[x])
	{
		if (!vis[i])//出边对应的点没有被访问
		{
			nxt[x] = i;//选择一条出边
			vis[i] = 1;
			dfs(pos + 1);
			vis[i] = 0;
		}
	}
}
int main()
{
#ifndef _Aya
	freopen("king.in", "r", stdin);
	freopen("king.out", "w", stdout);
#endif // !_Aya
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= m; ++i)
	{
		int u, v;
		scanf("%d%d", &u, &v);
		G[u].push_back(v);
	}
	for (int i = 1; i <= n; ++i)
		if (G[i].empty())//存在无出边的点
			failed();
	for (int i = 1; i <= n; ++i)
	{
		if (G[i].size() > 1)
			cpx.push_back(i);//记录出边大于1的点
		else//出边只有一条
		{
			if (vis[G[i][0]])//已经经过了
				failed();
			vis[G[i][0]] = 1;
		}
	}
	for (int i = 1; i <= n; ++i)
		nxt[i] = G[i][0];
	dfs(0);//处理多出边的情况
	failed();
	return 0;
}