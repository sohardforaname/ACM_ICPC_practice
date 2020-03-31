#include <bits/stdc++.h>
using namespace std;
int mp[20][20];
int f[1 << 20][20];
int solve(int n)
{
	memset(f, 0x3f3f3f3f, sizeof(f));
	f[1][0] = 0;
	for (int i = 1; i < (1 << n); ++i)
		for (int j = 0; j < n; ++j)
			if ((i >> j) & 1)
				for (int k = 0; k < n; ++k)
					if (((i ^ (1 << j)) >> k) & 1)
						f[i][j] = min(f[i][j], f[i ^ (1 << j)][k] + mp[k][j]);
	return f[(1 << n) - 1][n - 1];
}
int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			scanf("%d", &mp[i][j]);
	printf("%d\n", solve(n));
	return 0;
}
