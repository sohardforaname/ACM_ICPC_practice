#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <map>
#include <cassert>
using namespace std;
const int N = 3e2 + 5;
const char week[7][4] = { "MON","TUE","WED","THU","FRI","SAT","SUN" };
map<string, int>mp;
int n, m, p;
int a[N][N], x[N];
bool freex[N];
//m个方程，n个未知数
void init()
{
	for (int i = 0; i < 7; ++i)
		mp[week[i]] = i;
}
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
	{//回代求解
		int tmp = a[i][n];
		for (int j = i + 1; j < n; ++j)
			if (a[i][j])
				tmp = ((tmp - x[j] * a[i][j] % p) + p) % p;
		x[i] = tmp * inv(a[i][i], p) % p;
		a[i][i] = 0;
	}
	return 0;
}
int trans(int x)
{
	if (x > 9)
		x %= p;
	if (x < 3)
		x += p;
	return x;
}
char s1[4], s2[4];
int main()
{
	p = 7;
	init();
	while (scanf("%d%d", &n, &m) && n && m)
	{
		for (int i = 0; i < m; ++i)
			for (int j = 0; j <= n; ++j)
				a[i][j] = 0;
		int tmp, v;
		for (int i = 0; i < m; ++i)
		{
			scanf("%d%s%s", &tmp, s1, s2);
			a[i][n] = (mp[s2] - mp[s1] + p + 1) % p;
			for (int j = 0; j < tmp; ++j)
				scanf("%d", &v), a[i][v - 1] = (a[i][v - 1] + 1) % p;//系数一定要取模
		}
		int tag = Gauss(m, n, p);
		if (tag == -1)
			printf("Inconsistent data.\n");
		else if (tag > 0)
			printf("Multiple solutions.\n");
		else
			for (int i = 0; i < n; ++i)
				printf("%d%c", trans(x[i]), " \n"[i == n - 1]);
	}
	return 0;
}
