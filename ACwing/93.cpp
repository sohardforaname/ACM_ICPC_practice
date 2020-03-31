#include <bits/stdc++.h>
using namespace std;
int sta[55], cnt;
int n, m;
void dfs(int beg, int div)
{
	if (div == m)
	{
		if (cnt != m)
			return;
		for (int i = 0; i < m; ++i)
		{
			printf("%d", sta[i]);
			if (i < m - 1)
				printf(" ");
		}
		printf("\n");
		return;
	}
	for (int i = beg; i <= n; ++i)
	{
		sta[cnt++] = i;
		dfs(i + 1, div + 1);
		--cnt;
	}
	return;
}
int main()
{
	scanf("%d%d", &n, &m);
	dfs(1, 0);
	return 0;
}
