#include <bits/stdc++.h>
using namespace std;
const int MAXN = 4e2 + 5;
int mp1[MAXN][MAXN], mp2[MAXN][MAXN];//铁路，公路
int main()
{
	int n, m;
	memset(mp1, 0x3f, sizeof(mp1));
	for (int i = 1; i < MAXN; ++i)
		for (int j = 1; j <= MAXN; ++j)
			mp2[i][j] = 1;
	scanf("%d%d", &n, &m);
	int a, b;
	for (int i = 1; i <= m; ++i)
	{
		scanf("%d%d", &a, &b);
		mp1[a][b] = mp1[b][a] = 1;
		mp2[a][b] = mp2[b][a] = 0x3f3f3f3f;
	}
	for (int k = 1; k <= n; ++k)
		for (int i = 1; i <= n; ++i)
			for (int j = 1; j <= n; ++j)
			{
				mp1[i][j] = min(mp1[i][j], mp1[i][k] + mp1[k][j]);
				mp2[i][j] = min(mp2[i][j], mp2[i][k] + mp2[k][j]);
			}
	if (mp1[1][n] >= 0x3f3f3f3f || mp2[1][n] >= 0x3f3f3f3f)
		printf("-1\n");
	else
		printf("%d\n", max(mp1[1][n], mp2[1][n]));
	return 0;
}