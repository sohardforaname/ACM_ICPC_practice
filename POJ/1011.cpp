#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cstdio>
#include <cstring>
using namespace std;
int st[65];
bool vis[65];
int n;
bool dfs(int sum, int len, int pos, int cnt)//目前的棍子的总长度，应该达到的长度，当前访问第几根棍子，已使用棍子数量
{
	if (n == cnt)
		return 1;
	int sample = -1;
	for (int i = pos; i < n; ++i)
	{
		if (vis[i] || sample == st[i])//棍子在之前已经使用或者这种长度的棍子无法使用
			continue;
		vis[i] = 1;
		if (sum + st[i] < len)//还没有配好
		{
			if (dfs(sum + st[i], len, i, cnt + 1))
				return 1;
			else
				sample = st[i];
		}
		else if (sum + st[i] == len)//刚好配好
		{
			if (dfs(0, len, 0, cnt + 1))
				return 1;
			else
				sample = st[i];
		}
		vis[i] = 0;
		if (sum == 0)//上一根棍子配好了，但是这一根已经没办法配了。
			return 0;
	}
	return 0;
}
bool cmp(int a, int b)
{
	return a > b;
}
int main()
{
	while (scanf("%d", &n) && n)
	{
		bool flag = 0;
		int sum = 0;
		for (int i = 0; i < n; ++i)
			scanf("%d", &st[i]), sum += st[i];
		sort(st, st + n, cmp);
		//cout<<st[0]<<endl; 
		memset(vis, 0, sizeof(vis));
		for (int len = st[0]; len <= sum - len; ++len)
		{
			//cout<<len<<endl;
			if (sum % len == 0 && dfs(0, len, 0, 0))
			{
				printf("%d\n", len);
				flag = 1;
				break;
			}
		}
		if (!flag)
			printf("%d\n", sum);

	}
	return 0;
}