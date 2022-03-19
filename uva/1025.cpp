#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
bool train_t[1005][55][3];//时刻i在车站j有上行或者下行的火车
int t[55], u[55], d[55];
int dp[1005][55];//时刻i在j车站的最小时间
int main()
{
	int n, index = 1;
	while (cin >> n && n)
	{
		memset(train_t, 0, sizeof(train_t));
		int ti, k, l;
		cin >> ti;
		for (int i = 1; i <= n - 1; ++i)
			cin >> t[i];
		cin >> k;
		for (int i = 1; i <= k; ++i)
			cin >> u[i];
		cin >> l;	
		for (int i = 1; i <= l; ++i)
			cin >> d[i];
		for (int i = 1; i <= k; ++i)
		{
			int st = u[i];
			for (int j = 1; j <= n - 1; ++j)
			{ 
				train_t[st][j][1] = 1;
				st += t[j];
			}
			train_t[st][n][1] = 1;
		}
		for (int i = 1; i <= l; ++i)
		{
			int st = d[i];
			for (int j = n; j > 1; --j)
			{
				train_t[st][j][0] = 1;
				st += t[j - 1];
			}
			train_t[st][1][0] = 1;
		}
		memset(dp, 0x3f3f3f3f, sizeof(dp));
		dp[ti][n] = 0;
		for (int i = ti - 1; i >= 0; --i)
		{
			for (int j = 1; j <= n; ++j)
			{
				dp[i][j] = dp[i + 1][j] + 1;
				if (j < n && train_t[i][j][1] && i + t[j] <= ti)
					dp[i][j] = min(dp[i][j], dp[i + t[j]][j + 1]);
				if (j > 1 && train_t[i][j][0] && i + t[j - 1] <= ti)
					dp[i][j] = min(dp[i][j], dp[i + t[j - 1]][j - 1]);
			}
		}
		cout << "Case Number " << index++ << ": ";
		if (dp[0][1] >= 0x3f3f3f3f)
			cout << "impossible" << endl;
		else
			cout << dp[0][1] << endl;
	}
	return 0;
}