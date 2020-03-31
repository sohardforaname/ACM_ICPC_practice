#include <iostream>
#include <cstring>
#include <algorithm>
#define max(a,b) (a>b?a:b)
using namespace std;
bool map[105][12];
int st[105];
bool enable[1 << 10];
int dp[105][1 << 10][1 << 10];
bool check(int i)
{
	if (((i >> 1) & i) == 0 && ((i >> 2) & i) == 0 && ((i << 1) & 1) == 0 && ((i << 2) & i) == 0)
		return true; 
	return false;
}
int main()
{
	int n, m;
	char re;
	cin >> n >> m;
	getchar();
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			cin >> re;
			re == 'P' ? map[i][j] = 1 : map[i][j] = 0;
			st[i] = (st[i] << 1) + map[i][j];
		}
		getchar();
	}
	int maxstate = 1 << m;
	for (int i = 0; i < maxstate; ++i)
		if (check(i))
			enable[i] = 1;
	for (int i = 0; i < maxstate; ++i)
		if (enable[i] && (i & st[0]) == i)
			dp[0][i][0] = 1;
	for (int i = 1; i < n; ++i)//遍历所有行
	{
		for (int j = 0; j < maxstate; ++j)//遍历当前行状态
		{
			if (enable[j] && (j & st[i]) == j)//状态j是合法状态且j状态是实际状态的子集
			{
				for (int k = 0; k < maxstate; ++k)//遍历当前行的前一行状态
				{
					if ((k & j) == 0 && enable[k] && (k & st[i - 1]) == k)
					//状态k与状态j在任意一位上都不重合
					//状态j是合法状态且j状态是实际状态的子集
					{
						dp[i][j][k] = max(dp[i][j][k], dp[i - 1][k][0]);
						if (i > 1)
						{
							for (int l = 0; l < maxstate; ++l)//遍历当前行的前两行状态
							{
								if ((l & j) == 0 && enable[l] && (l & st[i - 2]) == l)
									//状态l与状态j在任意一位上都不重合
									//状态l是合法状态且l状态是实际状态的子集
								{
									dp[i][j][k] = max(dp[i][j][k], dp[i - 1][k][l]);
								}
							}
						}
					}
				}
			}
		}
	}
	long long ans = -1;
	for (int i = 0; i < maxstate; ++i)
		for (int j = 0; j < maxstate; ++j)
			ans = max(ans, dp[n - 1][i][j]);
	cout << ans << endl;
	return 0;
}