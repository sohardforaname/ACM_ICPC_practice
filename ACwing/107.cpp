#include <bits/stdc++.h>
using namespace std;
const int MAXN = 5e5 + 5;
int a[MAXN], tmp[MAXN];
long long merge(int l, int r)
{
	long long cnt = 0;
	if (l >= r)
		return 0;
	int mid = (l + r) >> 1;
	cnt += merge(l, mid);
	cnt += merge(mid + 1, r);
	int i = l, j = mid + 1, top = i;
	while (i <= mid || j <= r)
	{
		if (j > r || (i <= mid && a[i] <= a[j]))
			tmp[top++] = a[i++];
		else
			tmp[top++] = a[j++], cnt += mid - i + 1;
	}
	for (int i = l; i <= r; ++i)
		a[i] = tmp[i];
	return cnt;
}
int main()
{
	int n;
	while (scanf("%d", &n) && n)
	{
		for (int i = 0; i < n; ++i)
			scanf("%d", &a[i]);
		printf("%lld\n", merge(0, n - 1));
	}
	return 0;
}
