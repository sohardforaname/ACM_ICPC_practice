#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
typedef long long ll;
ll a[N], sum[N];
ll h[N], l[N], r[N];//l[i]，r[i]是i达到h时最左端最右端的高度
int n;
ll w;
ll cal(ll x, ll y, ll a)
{
	return (x + y) * a / 2;
}
bool check(ll h)
{
	ll ans = 0;
	memset(l, 0, sizeof(l));
	memset(r, 0x3f, sizeof(r));
	for (int i = 1; i <= n; ++i)
		if (i + h - a[i] <= n)
			l[i + h - a[i]] = i;
	for (int i = n; i; --i)
		if (i - h + a[i] > 0)
			r[i + a[i] - h] = i;
	for (int i = 1; i <= n; ++i)
		l[i] = max(l[i], l[i - 1]);
	for (int i = n; i; --i)
		r[i] = min(r[i], r[i + 1]);
	for (int i = 1; i <= n; ++i)
	{
		if (l[i] == 0 || r[i] == r[N - 1])
			continue;
		ans = 0;
		ans += cal(a[l[i]], h, i - l[i] + 1);
		ans += cal(a[r[i]], h - 1, r[i] - i);
		ans -= sum[r[i]] - sum[l[i] - 1];
		if (ans <= w)
			return 1;
	}
	return 0;
}
int main()
{
#ifndef _Aya
	freopen("landscape.in", "r", stdin);
	freopen("landscape.out", "w", stdout);
#endif // !_Aya

	scanf("%d%lld", &n, &w);
	ll l = 0, r, mid;
	for (int i = 1; i <= n; ++i)
	{
		scanf("%lld", &a[i]);
		sum[i] = sum[i - 1] + a[i];
		l = max(l, a[i]);
	}
	r = 2e9;
	ll ans = 0;
	while (l < r)
	{
		mid = (l + r) >> 1;
		if (check(mid))
			l = mid + 1, ans = mid;
		else
			r = mid;
	}
	printf("%lld\n", ans);
}
