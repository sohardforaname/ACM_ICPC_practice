#include <bits/stdc++.h>
using namespace std;
long long dp[15], f[15];
int main()
{
	dp[1] = 1;
	for (int i = 2; i <= 12; ++i)
		dp[i] = (dp[i - 1] << 1) + 1;
	f[1] = 1;
	for (int i = 2; i <= 12; ++i)
	{
		f[i] = (f[1] << 1) + dp[i - 1];
		for (int j = 2; j < i; ++j)
			f[i] = min(f[i], (f[j] << 1) + dp[i - j]);
	}
	for (int i = 1; i <= 12; ++i)
		printf("%lld\n", f[i]);
	return 0;
}
