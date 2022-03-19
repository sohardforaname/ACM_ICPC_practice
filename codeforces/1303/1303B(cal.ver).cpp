#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve()
{
	ll n, g, b;
	scanf("%lld%lld%lld", &n, &g, &b);
	ll tmp = (n + 1) / 2;
	ll tot = tmp / g * (g + b);
	if (tmp % g == 0)
		tot -= b;
	else
		tot += tmp % g;
	printf("%lld\n", max(tot, n));
}
int main()
{
	int t;
	scanf("%d", &t);
	while (t--)
		solve();
	return 0;
}