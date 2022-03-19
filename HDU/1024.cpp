#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;
int num[1000005];
long long dp[1000005];
long long ma[1000005];
const long long inf = 0x3f3f3f3f;
int main()
{
	int n, m;
	while (scanf("%d", &m) != EOF)
	{
		scanf("%d", &n);
		for (int i = 1; i <= n; ++i)
			scanf("%d", &num[i]);
		memset(dp, 0, sizeof(dp));
		memset(ma, 0, sizeof(ma));
		long long maxx;
		for (int i = 1; i <= m; ++i)
		{
			maxx = -inf;
			for (int j = i; j <= n; ++j)
			{
				dp[j] = max(dp[j - 1], ma[j - 1]) + num[j];
				ma[j - 1] = maxx;
				maxx = max(maxx, dp[j]);
			}
		}
		cout << maxx << endl;
	}
	return 0;
}