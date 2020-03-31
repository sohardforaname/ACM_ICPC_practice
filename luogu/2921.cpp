#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 5;
int dfn[MAXN], col[MAXN], minc[MAXN], inc[MAXN];
int nxt[MAXN], ans;
int cnt;
int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i)
		scanf("%d", &nxt[i]);
	for (int i = 1; i <= n; ++i)
	{
		int cnt = 0;
		int p = i;
		while (!col[p])
		{
			col[p] = i;
			dfn[p] = cnt++;
			p = nxt[p];
		}
		if (col[p] == i)
		{
			ans = cnt;
			minc[i] = cnt - dfn[p];
			inc[i] = dfn[p];//进入环的时间戳
		}
		else
		{
			minc[i] = minc[col[p]];
			inc[i] = cnt;
			if (inc[col[p]] > dfn[p])
				inc[i] += inc[col[p]] - dfn[p];
			ans = inc[i] + minc[i];
		}
		printf("%d\n", ans);
	}
	return 0;
}