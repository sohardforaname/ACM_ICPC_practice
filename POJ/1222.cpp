#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cassert>
using namespace std;
const int N = 16;
const int inf = 0x3f3f3f3f;
int a[N * N][N * N], x[N * N], freex[N * N];
// n values, m equations 
int Gauss(int m, int n)
{
	//memset(x, 0, sizeof(x[0]) * n);
	//memset(freex, 0, sizeof(freex[0]) * n);
	int row = 0, cnt = 0;
	for (int col = 0; row < m && col < n; ++row, ++col)
	{
		int maxr = row;
		for (int j = row + 1; j < m; ++j)
			if (abs(a[j][col]) > abs(a[maxr][col]))
				maxr = j;
		if (maxr != row)
			for (int j = row; j < n + 1; ++j)
				swap(a[maxr][j], a[row][j]);
		if (!a[row][col])
		{
			--row;
			freex[cnt++] = col;
			continue;
		}
		for (int j = row + 1; j < m; ++j)
			if (a[j][col])
				for (int k = col; k < n + 1; ++k)
					a[j][k] ^= a[row][k];
	}
	/*for (int i = n - 1; i >= 0; --i)
	{
		x[i] = a[i][n];
		for (int j = i + 1; j < n; ++j)
			x[i] ^= (a[i][j] && x[j]);
	}
	return 0;*/
	for (int i = row; i < m; ++i)
		if (a[i][n])
			return -1;
	return n - row;
}
int solve(int tag, int n)
{
	if (tag < 0)
		return inf;
	int ans = inf;
	for (int i = 0; i < (1 << tag); ++i)
	{
		int cnt = 0;
		memset(x, 0, sizeof(x[0]) * n);
		for (int j = 0; j < tag; ++j)
			if ((i >> j) & 1)
				x[freex[j]] = 1, ++cnt;
		for (int j = n - tag - 1; j >= 0; --j)
		{
			int tmp = a[j][n], tp = j, ok = 1;
			for (int k = j; k < n; ++k)
			{
				if (!a[j][k])
					continue;
				if (ok)
					ok = 0, tp = k;
				else
					tmp ^= x[k];
			}
			x[tp] = tmp;
			cnt += x[tp];
		}
		ans = min(ans, cnt);
	}
	return ans;
}
int n, m;
bool check(int x, int y)
{
	return x > -1 && x < n && y > -1 && y < m;
}
void init()
{
	for (int i = 0; i < n * m; ++i)
		for (int j = 0; j <= n * m; ++j)
			a[i][j] = 0;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
		{
			int t = i * m + j;
			a[t][t] = 1;
			if (check(i - 1, j))
				a[(i - 1) * m + j][t] = 1;
			if (check(i, j - 1))
				a[i * m + j - 1][t] = 1;
			if (check(i + 1, j))
				a[(i + 1) * m + j][t] = 1;
			if (check(i, j + 1))
				a[i * m + j + 1][t] = 1;
		}
}
int main()
{
	n = 5, m = 6;
	int T;
	scanf("%d", &T);
	for (int cas = 1; cas <= T; ++cas)
	{
		init();
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < m; ++j)
				scanf("%d", &a[i * m + j][n * m]);
		int tag = solve(Gauss(m * n, m * n), m * n);
		printf("PUZZLE #%d\n", cas);
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < m; ++j)
				printf("%d%c", x[i * m + j], " \n"[j == m - 1]);
	}
	return 0;
}