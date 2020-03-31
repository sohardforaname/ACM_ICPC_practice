#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll getlen(ll x)
{
	return x > 1 ? 1 + (getlen(x >> 1) << 1) : 1;
}
ll query(ll num, ll ql, ll qr, ll l, ll r)
{
	if (l <= ql && r >= qr)
		return num;
	ll m = ql + getlen(num >> 1);
	ll ans = 0;
	if (l <= m - 1)
		ans += query(num >> 1, ql, m - 1, l, r);
	if (l <= m && r >= m)
		ans += num % 2;
	if (r >= m + 1)
		ans += query(num >> 1, m + 1, qr, l, r);
	return ans;
}
int main()
{
	ll num;
	ll l, r;
	scanf("%lld%lld%lld", &num, &l, &r);
	ll len = getlen(num);
	printf("%lld\n", query(num, 1, len, l, r));
	return 0;
}