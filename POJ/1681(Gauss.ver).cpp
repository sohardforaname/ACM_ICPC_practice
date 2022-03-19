#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cassert>
#include <bitset>
using namespace std;
const int N = 16;
const int inf = 0x3f3f3f3f;
bitset<N * N> a[N * N];
int x[N * N], freex[N * N];
// n values, m equations
int Gauss(int m, int n)
{
	int row = 0, cnt = 0;
	for (int col = 0; row < m && col < n; ++row, ++col)
	{
		int maxr = row;
		for (int j = row + 1; j < m; ++j)
			if (abs(a[j][col]) > abs(a[maxr][col]))
				maxr = j;
		if (maxr != row)
			swap(a[row], a[maxr]);
		if (!a[row][col])
		{
			--row;
			freex[cnt++] = col;
			continue;
		}
		for (int j = row + 1; j < m; ++j)
			if (a[j][col])
				for (int k = col; k < n + 1; ++k)
					a[j][k] = a[j][k] ^ a[row][k];
	}
	for (int i = row; i < m; ++i)
		if (a[i][n])
			return -1;
	return n - row;
}
int solve(int tag, int n)
{
	memset(freex, 0, sizeof(freex[0]) * n);
	if (tag < 0)
		return tag;
	int ans = inf, cnt = 0;
	for (int i = 0; i < (1 << tag); ++i)
	{
		memset(x, 0, sizeof(x[0]) * n);
		for (int j = 0; j < tag; ++j)
			if ((i >> j) & 1)
				x[freex[j]] = 1;
		for (int i = n - tag - 1; i >= 0; --i)
		{
			int tmp = a[i][n], tp = 0, ok = 1;
			for (int j = i; j < n; ++j)
			{
				if (!a[i][j])
					continue;
				if (ok)
					ok = 0, tp = j;
				else
					tmp ^= x[j];
			}
			x[tp] = tmp;
			cnt += x[tp];
		}
		ans = min(ans, cnt);
	}
	return ans;
}
int n;
void init(int n, int m)
{
	for (int i = 0; i < n * m; ++i)
		for (int j = 0; j <= n * m; ++j)
			a[i][j] = 0;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
		{
			int t = i * m + j;
			a[t][t] = 1;
			if (i > 0)
				a[(i - 1) * m + j][t] = 1;
			if (i < n - 1)
				a[(i + 1) * m + j][t] = 1;
			if (j > 0)
				a[i * m + j - 1][t] = 1;
			if (j < m - 1)
				a[i * m + j + 1][t] = 1;
		}
}
char ch[N];
int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d", &n);
		init(n, n);
		for (int i = 0; i < n; ++i)
		{
			scanf("%s", ch);
			for (int j = 0; j < n; ++j)
				a[i * n + j][n * n] = ch[j] == 'y' ? 0 : 1;
		}
		int tag = solve(Gauss(n * n, n * n), n * n);
		if (tag == -1)
			printf("inf\n");
		else
		{
			int cnt = 0;
			for (int i = 0; i < n * n; ++i)
				cnt += x[i];
			printf("%d\n", cnt);
		}
	}
	return 0;
}