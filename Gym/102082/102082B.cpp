#include <bits/stdc++.h>
using namespace std;
int num[5005];
int dp[5005][5005];
int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i)
		scanf("%d", &num[i]);
	sort(num + 1, num + n + 1);
	int l;
	int ans = 0;
	for (int i = 1; i <= n; ++i)
	{
		l = i - 1;
		for (int j = i + 1; j <= n; ++j)
		{
			dp[i][j] = 2;
			while (l >= 1 && num[j] - num[i] > num[i] - num[l])
				--l;
			if (l >= 1 && num[i] - num[l] == num[j] - num[i])
				dp[i][j] = dp[l][i] + 1;
			ans = max(ans, dp[i][j]);
		}
	}
	printf("%d\n", ans);
	return 0;
}
