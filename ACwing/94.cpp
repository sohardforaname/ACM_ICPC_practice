#include <bits/stdc++.h>
using namespace std;
int sta[15], cnt;
int vis[15];
int n;
void dfs(int div)
{
	if (div == n)
	{
		for (int i = 0; i < n; ++i)
			printf("%d%c", sta[i], i == n - 1 ? '\n' : ' ');
		return;
	}
	for (int i = 1; i <= n; ++i)
	{
		if (!vis[i])
		{
			vis[i] = 1;
			sta[cnt++] = i;
			dfs(div + 1);
			--cnt;
			vis[i] = 0;
		}
	}
	return;
}
int main()
{
	scanf("%d", &n);
	dfs(0);
	return 0;
}
