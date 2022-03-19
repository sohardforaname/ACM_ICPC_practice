#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll gcd(ll a, ll b)
{
	return !b ? a : gcd(b, a % b);
}
void solve()
{
	ll a, m;
	scanf("%lld%lld", &a, &m);
	ll g = gcd(a, m);
	m /= g;
	ll phi = m;
	for (ll i = 2; i * i <= m; ++i)
		if (m % i == 0)
		{
			phi = phi / i * (i - 1);
			while (m % i == 0)
				m /= i;
		}
	if (m > 1)
		phi = phi / m * (m - 1);
	printf("%lld\n", phi);
}
int main()
{
	int t;
	scanf("%d", &t);
	while (t--)
		solve();
	return 0;
}
/*
get x for gcd(a, m) = gcd(a + x, m), gcd(a, m)=gcd(a + x - k * m, m), assume x' = (a + x) % m.
so that get x' for gcd(x', m) = gcd(a, m);
g = gcd(a, m)=g' * gcd(a', m') and gcd(a', m') = 1,so 
gcd(x', m) = g * gcd(a', m'), get phi(m').
*/