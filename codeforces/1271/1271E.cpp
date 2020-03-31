#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n, k;
bool check(ll m)
{
	ll l = m, r = m;
	if (!(m & 1))
		++r;
	ll res = 0;
	while (l <= n)
	{
		res += min(n, r) - l + 1;
		l = l << 1;
		r = (r << 1) + 1;
	}
	return res >= k;
}
int main()
{
	scanf("%lld%lld", &n, &k);
	ll l, r, m, ans = 0;
	l = 1, r = (n + 1) >> 1;
	while (l <= r)
	{
		m = (l + r) >> 1;
		if (check((m << 1) - 1))
		{
			ans = (m << 1) - 1;
			l = m + 1;
		}
		else
			r = m - 1;
	}
	l = 1, r = n >> 1;
	while (l <= r)
	{
		m = (l + r) >> 1;
		if (check(m << 1))
		{
			ans = max(ans, m << 1);
			l = m + 1;
		}
		else
			r = m - 1;
	}
	printf("%lld\n", ans);
	return 0;
}