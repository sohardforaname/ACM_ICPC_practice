#include <bits/stdc++.h>
using namespace std;
const int N = 2e3 + 5;
typedef long long ll;
int a[N], n, k;
int dp[N]; //第i个数字不变并且前i个数字两两相邻绝对值小于mid需要改变的数个数
bool check(ll num)
{
	for (int i = 1; i <= n; ++i)
	{
		dp[i] = i - 1;
		for (int j = 1; j < i; ++j)
			if (abs(a[j] - a[i]) <= num * (i - j))
				dp[i] = min(dp[i], dp[j] + i - j - 1);
	}
	if (dp[n] <= k)
		return 1;
	for (int i = 1; i <= n; ++i)
		if (dp[i] + n - i <= k)
			return 1;
	return false;
}
int main()
{
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= n; ++i)
		scanf("%d", &a[i]);
	ll l = 0, r = 2e9;
	int cnt = 0;
	while (l < r)
	{
		ll m = (l + r) >> 1;
		if (check(m))
			r = m;
		else
			l = m + 1;
		++cnt;
		assert(cnt < 1e5);
	}
	printf("%lld\n", l);
	return 0;
}
