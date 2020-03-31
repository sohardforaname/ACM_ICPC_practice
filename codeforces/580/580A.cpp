#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
int num[100005];
int dp[100005];
int main()
{
	dp[0] = 0;
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i)
		scanf("%d", &num[i]);
	int len = 0, ans = 0;
	for (int i = 1; i <= n; ++i)
	{
		if (num[i] >= num[i - 1])
			++len;
		else
			len = 1;
		ans = max(ans, len);
	}
	printf("%d\n", ans);
	return 0;
}