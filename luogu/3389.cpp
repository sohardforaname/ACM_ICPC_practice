#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;
const int N = 1010;
const double EPS = 1e-7;
int m, n;
double a[N][N], x[N];
bool freex[N];
//m个方程，n个未知数
int Gauss(int m, int n)
{
	for (int i = 0; i < n; ++i)
		x[i] = 0, freex[i] = 1;
	int col, k;//col为列号,k为行号
	for (k = 0, col = 0; k < m && col < n; ++k, ++col)
	{
		int r = k;
		for (int i = k + 1; i < m; ++i)
			if (fabs(a[i][col]) > fabs(a[r][col]))
				r = i;
		if (fabs(a[r][col]) < EPS) 
		{ 
			k--;
			continue; 
		}//列全为0
		if (r != k)
			for (int i = col; i <= n; ++i)
				swap(a[k][i], a[r][i]);
		for (int i = k + 1; i < m; ++i)//消元
			if (fabs(a[i][col]) > EPS) 
			{
				double t = a[i][col] / a[k][col];
				for (int j = col; j <= n; j++)
					a[i][j] -= a[k][j] * t;
				a[i][col] = 0;
			}
	}
	for (int i = k; i < m; ++i)//无解
		if (fabs(a[i][n]) > EPS) 
			return -1;
	if (k < n)
	{
		for (int i = k - 1; i >= 0; --i)
		{
			int free_num = 0, free_index = 0;
			for (int j = 0; j < n; ++j)
				if (fabs(a[i][j]) > EPS&& freex[j])
					++free_num, free_index = j;
			if (free_num > 1)
				continue;
			double tmp = a[i][n];
			for (int j = 0; j < n; ++j)
				if (fabs(a[i][j]) > EPS&& j != free_index)
					tmp -= a[i][j] * x[j];
			x[free_index] = tmp / a[i][free_index];
			freex[free_index] = 0;
		}
		return n - k;  //自由元个数
	}
	for (int i = n - 1; i >= 0; i--)
	{//回带求解
		double tmp = a[i][n];
		for (int j = i + 1; j < n; ++j)
			if (fabs(a[i][j]) > EPS)
				tmp -= x[j] * a[i][j];
		x[i] = tmp / a[i][i];
		a[i][i] = 0;
	}
	return 0;
}
int main()
{
	int n, m;
	scanf("%d", &n);
	m = n;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j <= m; ++j)
			scanf("%lf", &a[i][j]);
	int tag = Gauss(n, m);
	/*if (tag > 0)
		for (int i = 0; i < m; ++i)
		{
			if (!freex[i])
				printf("%.6f\n", x[i]);
			else
				printf("Not certain\n");
		}*/
	if (tag)
		printf("No Solution\n");
	else
		for (int i = 0; i < m; ++i)
			printf("%.2f\n", x[i]);
	return 0;
}
