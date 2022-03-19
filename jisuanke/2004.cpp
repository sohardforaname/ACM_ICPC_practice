#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e4 + 5;
const int mod = 10007;
ll fac[N];
void init()
{
	fac[0] = 1;
	for (int i = 1; i < N; ++i)
		fac[i] = fac[i - 1] * i % mod;
}
ll qmul(ll a, ll b, ll p)
{
	ll res = 0;
	while (b)
	{
		if (b & 1)
			res = (res + a) % p;
		a = (a + a) % p;
		b >>= 1;
	}
	return res;
}
ll qpow(ll a, ll b, ll p)
{
	ll res = 1;
	while (b)
	{
		if (b & 1)
			res = qmul(res, a, p);
		a = qmul(a, a, p);
		b >>= 1;
	}
	return res;
}
ll comb(ll a, ll b, ll p)
{
	return a < b ? 0 : (fac[a] * qpow(fac[b], p - 2, p) % p) * qpow(fac[a - b], p - 2, p) % p;
}
ll lucas(ll a, ll b, ll p)
{
	ll ans = 1;
	while (a && b)
	{
		ans = ans * comb(a % p, b % p, p) % p;
		a /= p;
		b /= p;
	}
	return ans;
}
int main()
{
	init();
	ll a, b, n, m, k;
	scanf("%lld%lld%lld%lld%lld", &a, &b, &k, &n, &m);
	printf("%lld", (lucas(k, n, mod) * qpow(a, n, mod) % mod) * qpow(b, m, mod) % mod);
	return 0;
}