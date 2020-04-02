#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll gcd(ll a, ll b)
{
	return !b ? a : gcd(b, a % b);
}
int main()
{
	int n;
	scanf("%d", &n);
	ll a, b, aa, bb;
	scanf("%lld%lld", &aa, &bb);
	for (int i = 2; i <= n; ++i)
	{
		scanf("%lld%lld", &a, &b);
		aa = gcd(aa, a * b);
		bb = gcd(bb, a * b);
	}
	aa = max(aa, bb);
	if (aa > 1)
	{
		for (ll i = 2; i * i <= aa; ++i)
			if (aa % i == 0)
				return printf("%lld\n", i), 0;
		return printf("%lld\n", aa), 0;
	}
	return printf("%lld\n", -1ll), 0;
}