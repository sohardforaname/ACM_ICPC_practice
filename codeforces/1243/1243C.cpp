#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll gcd(ll a, ll b)
{
	return b == 0 ? a : gcd(b, a % b);
}
int main()
{
	ll num;
	scanf("%lld", &num);
	ll ans = num;
	for (int i = 2; i <= sqrt(num); ++i)
		if (num % i == 0)
		{
			ans = gcd(ans, i);
			ans = gcd(ans, num / i);
		}
	printf("%lld\n", ans);
	return 0;
}