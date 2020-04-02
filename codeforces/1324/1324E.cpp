#include <bits/stdc++.h>
using namespace std;
const int N = 2e3+ 5;
typedef long long ll; 
int dp[N][N], sum[N];
void solve()
{
	int n, h, l, r, a;
	scanf("%d%d%d%d", &n, &h, &l, &r);
	for (int i = 1; i <= n; ++i)
	{
		scanf("%d", &a);
		sum[i] = sum[i - 1] + a;
	}
	for (int i = 1; i <= n; ++i)
		for (int j = 0; j <= i; ++j)
		{
			bool f = (l <= (sum[i] - j) % h && (sum[i] - j) % h <= r);
			if (j)
				dp[i][j] = max(dp[i][j], max(dp[i - 1][j] + f, dp[i - 1][j - 1] + f));
			else
				dp[i][j] = max(dp[i][j], dp[i - 1][j] + f);
		}
	int maxn = 0;
	for (int j = 0; j <= n; ++j)
		maxn = max(maxn, dp[n][j]);
	printf("%d\n", maxn);
}
int main()
{
	int T = 1;
	//scanf("%d", &T);
	while (T--)
		solve();
	return 0;
}