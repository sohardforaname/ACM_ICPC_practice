#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 5e3 + 5, tot = 5e3;
int fac[N][N];
int num[N], maxpri[N];
void getfac(int n)
{
	for (int i = 2; i <= n; ++i)
	{
		for (int j = 1; j < i; ++j)
			fac[i][j] += fac[i - 1][j];
		int tmp = i;
		for (int j = 2; j * j <= tmp; ++j)
			while (tmp % j == 0)
				++fac[i][j], tmp /= j;
		if (tmp > 1)
			++fac[i][tmp];
	}
}
int main()
{
	getfac(tot);//求得所有数的唯一分解
	int n, a;
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i)
	{
		scanf("%d", &a);
		++num[a];//统计数量
	}
	ll minn = 0, sz = 0;
	for (int i = 1; i <= tot; ++i)
	{
		if (!num[i])
			continue;
		for (int j = 1; j <= i; ++j)
		{
			sz += 1ll * fac[i][j] * num[i];//假设所求点是1
			if (fac[i][j])
				maxpri[i] = j;//找到最大的素因子
		}
	}
	minn = sz;
	while (1)
	{
		vector<ll>v(N, 0);
		for (int i = 1; i <= tot; ++i)
			if (num[i])
				v[maxpri[i]] += num[i];
		int pos = max_element(v.begin() + 1, v.end()) - v.begin();
		ll val = v[pos];//找到出现最多的值的路径
		if ((val << 1) <= n || pos <= 1)//就是1了
			break;
		sz -= (val << 1) - n;//减小
		minn = min(minn, sz);//更新最小值
		for (int i = 1; i <= tot; ++i)
		{
			if (!num[i])
				continue;
			if (maxpri[i] != pos)//非出现最多的值的路径，已经无用
				maxpri[i] = 0;
			if (maxpri[i])//往深度大的方向移一位
				--fac[i][maxpri[i]];
			while (maxpri[i] > 0 && !fac[i][maxpri[i]])//这个素因子的所有数都移动完了，需要换更小的继续移动
				--maxpri[i];
		}
	}
	printf("%lld\n", minn);
	return 0;
}
