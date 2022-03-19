#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;
const int N = 1e2 + 5;
int m, n, p;
int a[N][N], x[N];
bool freex[N];
//m个方程，n个未知数
int qpow(int a, int b, int p)
{
	int res = 1;
	while (b)
	{
		if (b & 1)
			res = res * a % p;
		a = a * a % p;
		b >>= 1;
	}
	return res;
}
int inv(int a, int p)
{
	return qpow(a, p - 2, p);
}
int Gauss(int m, int n, int p)
{
	for (int i = 0; i < n; ++i)
		x[i] = 0, freex[i] = 1;
	int col, k;//col为列号,k为行号
	for (k = 0, col = 0; k < m && col < n; ++k, ++col)
	{
		int r = k;
		for (int i = k + 1; i < m; ++i)
			if (abs(a[i][col]) > abs(a[r][col]))
				r = i;
		if (!a[r][col])
		{
			k--;
			continue;
		}//列全为0
		if (r != k)
			for (int i = col; i <= n; ++i)
				swap(a[k][i], a[r][i]);
		for (int i = k + 1; i < m; ++i)//消元
			if (a[i][col])
			{
				int t = a[i][col] * inv(a[k][col], p) % p;
				for (int j = col; j <= n; j++)
					a[i][j] = ((a[i][j] - a[k][j] * t % p) + p) % p;
				a[i][col] = 0;
			}
	}
	for (int i = k; i < m; ++i)//无解
		if (a[i][n])
			return -1;
	if (k < n)
	{
		for (int i = k - 1; i >= 0; --i)
		{
			int free_num = 0, free_index = 0;
			for (int j = 0; j < n; ++j)
				if (a[i][j] && freex[j])
					++free_num, free_index = j;
			if (free_num > 1)
				continue;
			int tmp = a[i][n];
			for (int j = 0; j < n; ++j)
				if (a[i][j] && j != free_index)
					tmp = ((tmp - a[i][j] * x[j] % p) + p) % p;
			x[free_index] = tmp * inv(a[i][free_index], p) % p;
			freex[free_index] = 0;
		}
		return n - k;  //自由元个数
	}
	for (int i = n - 1; i >= 0; i--)
	{//回带求解
		int tmp = a[i][n];
		for (int j = i + 1; j < n; ++j)
			if (a[i][j])
				tmp = ((tmp - x[j] * a[i][j] % p) + p) % p;
		x[i] = tmp * inv(a[i][i], p) % p;
		a[i][i] = 0;
	}
	return 0;
}
char s[N];
int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d%s", &p, s);
		int len = strlen(s);
		for (int i = 0; i < len; ++i)
		{
			a[i][0] = 1;
			for (int j = 1; j < len; ++j)
				a[i][j] = a[i][j - 1] * (i + 1) % p;
			a[i][len] = s[i] == '*' ? 0 : s[i] - 'a' + 1;
		}
		int tag = Gauss(len, len, p);
		for (int i = 0; i < len; ++i)
			printf("%d%c", x[i], " \n"[i == len - 1]);
	}
	return 0;
}
