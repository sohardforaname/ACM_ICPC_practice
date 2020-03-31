#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll phi(ll n)
{
	ll res = n, a = n;
	for (ll i = 2; i * i <= a; ++i)
		if (a % i == 0)
		{
			res = res / i * (i - 1);
			while (a % i == 0)
				a /= i;
		}
	if (a > 1)//处理2和3
		res = res / a * (a - 1);
	return res;
}
int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		ll num;
		scanf("%lld", &num);
		printf("%lld\n", phi(num));
	}
	return 0;
}