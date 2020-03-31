#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
long long num[25][25][25];
long long dfs(long long a, long long b, long long c)
{
	if (num[a][b][c])
		return num[a][b][c];
	if (a <= 0 || b <= 0 || c <= 0)
		return 1;
	else if (a > 20 || b > 20 || c > 20)
		return dfs(20, 20, 20);
	else if (a < b && b < c)
		num[a][b][c] = dfs(a, b, c - 1) + dfs(a, b - 1, c - 1) - dfs(a, b - 1, c);
	else
		num[a][b][c] = dfs(a - 1, b, c) + dfs(a - 1, b - 1, c) + dfs(a - 1, b, c - 1) - dfs(a - 1, b - 1, c - 1);
	return num[a][b][c];
}
int main()
{
	long long a, b, c, a1, b1, c1;
	while (scanf("%lld%lld%lld", &a, &b, &c) && !(a == -1 && b == -1 && c == -1))
	{
		if (a <= 0 || b <= 0 || c <= 0)
			a1 = 0, b1 = 0, c1 = 0;
		else if (a > 20 || b > 20 || c > 20)
			a1 = 20, b1 = 20, c1 = 20;
		else
			a1 = a, b1 = b, c1 = c;
		printf("w(%lld, %lld, %lld) = %lld\n", a, b, c, dfs(a1, b1, c1));
	}
	return 0;
}