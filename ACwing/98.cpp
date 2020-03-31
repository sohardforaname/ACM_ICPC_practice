#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
pair<ll, ll> calc(int n, ll m)
{
	if (n == 0)
		return make_pair(0, 0);
	ll len = 1ll << (n - 1), cnt = 1ll << ((n << 1) - 2);
	auto p = calc(n - 1, m % cnt);
	ll x = p.first, y = p.second;
	ll z = m / cnt;
	if (z == 0)
		return make_pair(y, x);
	else if (z == 1)
		return make_pair(x, y + len);
	else if (z == 2)
		return make_pair(x + len, y + len);
	else if (z == 3)
		return make_pair(-y + (len << 1) - 1, -x + len - 1);
}
double dist(pair<ll, ll>& a, pair<ll, ll>& b)
{
	return sqrt((a.first - b.first) * (a.first - b.first) + (a.second - b.second) * (a.second - b.second));
}
int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		int n;
		ll s, d;
		scanf("%d%lld%lld", &n, &s, &d);
		auto p1 = calc(n, s - 1), p2 = calc(n, d - 1);
		double dis = dist(p1, p2);
		printf("%0.0f\n", dis * 10);
	}
	return 0;
}
