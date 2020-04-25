#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
typedef long long ll;
bool check(ll n, ll g, ll b, ll t)
{
	return (n + 1) / 2 <= t / (g + b) * g + min(g, t % (g + b));
}
void solve()
{
	ll n, g, b;
	scanf("%lld%lld%lld", &n, &g, &b);
	ll l = n, r = 1e18;
	while (l < r)
	{
		ll m = (l + r) >> 1;
		if (check(n, g, b, m))
			r = m;
		else
			l = m + 1;
	}
	printf("%lld\n", l);
}
int main()
{
	int t;
	scanf("%d", &t);
	while (t--)
		solve();
	return 0;
}
