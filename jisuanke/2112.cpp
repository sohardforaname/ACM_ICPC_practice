#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
ll gcd(ll a, ll b)
{
	return !b ? a : gcd(b, a % b);
}
int main()
{
	ll a, b;
	scanf("%lld%lld", &a, &b);
	ll mul = a * b;
	ll sqr = sqrt(mul), ans = 0;
	for (int i = a; i < sqr; ++i)
		if (mul % i == 0)
		{
			ll _gcd = gcd(i, mul / i);
			if (_gcd == a && mul / _gcd == b)
				++ans;
		}
	ans *= 2;
	if (a == sqr)
		++ans;
	printf("%lld\n", ans);
	return 0;
}