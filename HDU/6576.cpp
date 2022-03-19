#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e3 + 5;
ll a[N];
ll gcd(ll a, ll b)
{
	return !b ? a : gcd(b, a % b);
}
ll lcm(ll a, ll b)
{
	return a * b / gcd(a, b);
}
int main()
{
	int n;
	ll m;
	while (~scanf("%d%lld", &n, &m))
	{
		for (int i = 1; i <= n; ++i)
			scanf("%lld", &a[i]);
		ll _lcm = a[1];
		for (int i = 2; i <= n; ++i)
			_lcm = lcm(_lcm, a[i]);
		ll sum = 0;
		for (int i = 1; i <= n; ++i)
			a[i] = _lcm / a[i], sum += a[i];
		if (m % sum)
			printf("No\n");
		else
		{
			printf("Yes\n");
			for (int i = 1; i <= n; ++i)
				printf("%lld%c", a[i] * (m / sum), " \n"[i == n]);
		}
	}
	return 0;
}