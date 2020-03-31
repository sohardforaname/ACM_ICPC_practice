#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e3 + 5;
int num[MAXN], sum[MAXN][MAXN], p[MAXN][2];
int top, n, c;
bool check(int len)
{
	int ans;
	for (int xl = 0, xr = 1; xr <= top; ++xr)
	{
		while (xl < xr && num[xr] - num[xl + 1] + 1 > len)
			++xl;
		for (int yl = 0, yr = 1; yr <= top; ++yr)
		{
			while (yl < yr && num[yr] - num[yl + 1] + 1 > len)
				++yl;
			ans = sum[xr][yr] - sum[xl][yr] - sum[xr][yl] + sum[xl][yl];
			if (ans >= c)
				return true;
		}
	}
	return false;
}
int main()
{
	scanf("%d%d", &c, &n);
	for (int i = 1; i <= n; ++i)
	{
		scanf("%d%d", &p[i][0], &p[i][1]);
		num[++top] = p[i][0], num[++top] = p[i][1];
	}
	sort(num + 1, num + n * 2 + 1);
	top = unique(num + 1, num + n * 2 + 1) - num;
	for (int i = 1; i <= n; ++i)
		for (int j = 0; j <= 1; ++j)
			p[i][j] = lower_bound(num, num + top, p[i][j]) - num;
	for (int i = 1; i <= n; ++i)
		++sum[p[i][0]][p[i][1]];
	for (int i = 1; i <= top; ++i)
		for (int j = 1; j <= top; ++j)
			sum[i][j] += sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1];
	int l = 1, r = 1e4;
	while (l < r)
	{
		int m = (l + r) >> 1;
		if (check(m))
			r = m;
		else
			l = m + 1;
	}
	printf("%d\n", l);
	return 0;
}