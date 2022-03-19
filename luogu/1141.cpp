#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e3 + 5;
bool G[MAXN][MAXN];
int col[MAXN][MAXN];//结点颜色
int tot[MAXN * MAXN];//颜色块的数量
int cnt, n, m;
int dir[4][2] = { {0,1},{0,-1},{1,0},{-1,0} };
bool check(int x, int y)
{
	return x <= n && x >= 1 && y <= n && y >= 1;
}
void dfs(int x, int y, int c)
{
	col[x][y] = c;
	++cnt;
	for (int i = 0; i < 4; ++i)
	{
		int x1 = x + dir[i][0], y1 = y + dir[i][1];
		if (check(x1, y1) && G[x][y] != G[x1][y1] && !col[x1][y1])
			dfs(x1, y1, c);
	}
}
char str[MAXN];
int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; ++i)
	{
		scanf("%s", str + 1);
		for (int j = 1; j <= n; ++j)
			G[i][j] = str[j] - '0';
	}
	int c = 0;
	for(int i=1;i<=n;++i)
		for(int j=1;j<=n;++j)
			if (!col[i][j])
			{
				cnt = 0;
				dfs(i, j, ++c);
				tot[c] = cnt;
			}
	int a, b;
	for (int i = 1; i <= m; ++i)
	{
		scanf("%d%d", &a, &b);
		printf("%d\n", tot[col[a][b]]);
	}
	return 0;
}