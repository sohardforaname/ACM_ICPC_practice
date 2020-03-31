#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 5;
int a[N], dp[N][N][2];//第i位用了j个偶数，第i位是奇数(1)/偶数(1)
int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i)
		scanf("%d", &a[i]);
	memset(dp, 0x3f, sizeof(dp));
	dp[0][0][0] = dp[0][0][1] = 0;
	for (int i = 1; i <= n; ++i)
		for (int j = 0; j <= i; ++j)
		{
			if (a[i] % 2 == 1 || a[i] == 0)//这一位是奇数
				dp[i][j][1] = min(dp[i - 1][j][1], dp[i - 1][j][0] + 1);
			if (a[i] % 2 == 0 && j)
				dp[i][j][0] = min(dp[i - 1][j - 1][0], dp[i - 1][j - 1][1] + 1);
		}
	printf("%d\n", min(dp[n][n / 2][0], dp[n][n / 2][1]));
	return 0;
}