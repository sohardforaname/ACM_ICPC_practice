#include <bits/stdc++.h>
using namespace std;
const int MAXN = 5e5 + 5;
long long a[MAXN], tmp[MAXN], cal[MAXN];
void merge(int l, int m, int r)
{
	int i = l, j = m + 1;
	int top = l;
	while (i <= m || j <= r)
	{
		if (j > r || (i <= m && tmp[i] <= tmp[j]))
			cal[top++] = tmp[i++];
		else
			cal[top++] = tmp[j++];
	}
}
bool calc(int l, int r, int m, long long t)
{
	long long ans = 0, res;
	for (int i = 0; i < m; ++i)
	{
		if (l >= r)
			break;
		res = (cal[r--] - cal[l++]);
		ans += res * res;
	}
	if (ans <= t)
		return true;
	else
		return false;
}
bool check(int l, int mid, int r, int m, long long t)
{
	memcpy(tmp + mid + 1, a + mid + 1, sizeof(a[0]) * (r - mid));
	sort(tmp + mid + 1, tmp + r + 1);
	merge(l, mid, r);
	if (calc(l, r, m, t))
	{
		memcpy(tmp + l, cal + l, sizeof(cal[0]) * (r - l + 1));
		return true;
	}
	else
		return false;
}
void solve(int ql, int qr, int m, long long t)
{
	int l = ql, len = 1, r = ql, ans = 0;
	tmp[l] = a[l];
	while (r <= qr)
	{
		if (!len)
		{
			++ans;
			len = 1;
			l = (++r);
			tmp[l] = a[l];
		}
		else if (r + len <= qr && check(l, r, r + len, m, t))
		{
			r += len;
			len <<= 1;
			if (r == qr)
				break;
		}
		else
			len >>= 1;
	}
	if (r == qr)
		++ans;
	printf("%d\n", ans);
}
int main()
{
	int T;
	int n, m;
	long long t;
	scanf("%d", &T);
	while(T--)
	{
		scanf("%d%d%lld", &n, &m, &t);
		for (int i = 0; i < n; ++i)
			scanf("%lld", &a[i]);
		solve(0, n - 1, m, t);
	}
	return 0;
}
