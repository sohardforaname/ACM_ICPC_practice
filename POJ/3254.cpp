// 3254.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
bool map[15][15];
long situa[15];
int dp[15][4200];//状态2^12，行数12
bool enable[4200];
const int M = 1e8;
int main()
{
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; ++i)
	{
		situa[i] = 0;
		for (int j = 1; j <= m; ++j)
		{
			cin >> map[i][j];
			situa[i] = (situa[i] << 1) + map[i][j];//左移一位，然后加上新读入的尾数
		}
	}
	int maxstate = 1 << m;
	for (int i = 0; i < maxstate; ++i)
		if (((i&(i << 1)) == 0 && ((i&(i >> 1)) == 0)))//保证i的为1的每一位的相邻位都不是1
			enable[i] = 1;
	for (int i = 0; i < maxstate; ++i)
		if ((enable[i] && (i & situa[1]) == i))//i合法且状态i对于实际地图合法
			dp[1][i] = 1;
	for (int i = 2; i <= n; ++i)
	{
		for (int j = 0; j < maxstate; ++j)
		{
			if (enable[j] && ((j & situa[i]) == j))//同理
				for (int k = 0; k < maxstate; ++k)
				{
					if ((k&j) == 0)
						dp[i][j] = (dp[i][j] + dp[i - 1][k]) % M;//状态递推增加
				}
		}
	}
	long long ans = 0;
	for (int i = 0; i < maxstate; ++i)
	{
		ans = (ans + dp[n][i]) % M;
	}
	cout << ans << endl;
	return 0;
}
