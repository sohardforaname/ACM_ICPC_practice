#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2.5e5 + 5;
int a[MAXN], tmp[MAXN];
long long merge(int l, int r)
{
	long long cnt = 0;
	if (l >= r)
		return 0;
	int m = (l + r) >> 1;
	cnt += merge(l, m);
	cnt += merge(m + 1, r);
	int i = l, j = m + 1, t = l;
	while (i <= m || j <= r)
	{
		if (j > r || (i <= m && a[i] <= a[j]))
			tmp[t++] = a[i++];
		else
			tmp[t++] = a[j++], cnt += m + 1 - i;
	}
	for (int i = l; i <= r; ++i)
		a[i] = tmp[i];
	return cnt;
}
int main()
{
	int n;
	while (~scanf("%d", &n))
	{
		int cnt = 0, k;
		for (int i = 0; i < n * n; ++i)
		{
			scanf("%d", &k);
			if (k)
				a[cnt++] = k;
		}
		long long ans1 = merge(0, cnt - 1);
		cnt = 0;
		for (int i = 0; i < n * n; ++i)
		{
			scanf("%d", &k);
			if (k)
				a[cnt++] = k;
		}
		long long ans2 = merge(0, cnt - 1);
		if (ans1 % 2 == ans2 % 2)
			printf("TAK\n");
		else
			printf("NIE\n");
	}
	return 0;
}
