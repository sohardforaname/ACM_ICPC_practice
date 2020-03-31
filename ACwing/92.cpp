#include <bits/stdc++.h>
using namespace std;
int sta[20], cnt;
int n;
void dfs(int beg, int div, int lim)
{
	if (div == lim)
	{
		for (int i = 0; i < lim; ++i)
		{
			printf("%d", sta[i]);
			if (i < lim - 1)
				printf(" ");
		}
		printf("\n");
		return;
	}
	for (int i = beg; i <= n; ++i)
	{
		sta[cnt++] = i;
		dfs(i + 1, div + 1, lim);
		--cnt;
	}
	return;
}
int main()
{
	scanf("%d", &n);
	for (int i = 0; i <= n; ++i)
		dfs(1, 0, i);
	return 0;
}
