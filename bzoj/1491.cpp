#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN = 1e2 + 5;
const int INF = 0x3f3f3f3f;
int G[MAXN][MAXN];
ll cnt[MAXN][MAXN];
double ans[MAXN];
int main()
{
	int n, m, a, b, c;
	scanf("%d%d", &n, &m);
	memset(G, 0x3f, sizeof(G));
	memset(cnt, 0, sizeof(cnt));
	for (int i = 1; i <= n; ++i)
		G[i][i] = 0;
	for (int i = 1; i <= m; ++i)
	{
		scanf("%d%d%d", &a, &b, &c);
		G[a][b] = G[b][a] = c;
		cnt[a][b] = cnt[b][a] = 1;
	}
	for (int k = 1; k <= n; ++k)
		for (int i = 1; i <= n; ++i)
			for (int j = 1; j <= n; ++j)
			{
				if (G[i][k] >= INF && G[k][j] >= INF)
					continue;
				if (G[i][j] > G[i][k] + G[k][j])
				{
					G[i][j] = G[i][k] + G[k][j];
					cnt[i][j] = cnt[i][k] * cnt[k][j];
				}
				else if (G[i][j] == G[i][k] + G[k][j])
					cnt[i][j] += cnt[i][k] * cnt[k][j];
			}
	for (int k = 1; k <= n; ++k)
		for (int i = 1; i <= n; ++i)
			for (int j = 1; j <= n; ++j)
			{
				if (i == j || i == k || j == k)
					continue;
				if (G[i][j] == G[i][k] + G[k][j])
					ans[k] += 1.0 * cnt[i][k] * cnt[k][j] / cnt[i][j];
			}
	for (int i = 1; i <= n; ++i)
		printf("%.3f\n", ans[i]);
	return 0;
}