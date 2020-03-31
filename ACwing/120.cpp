#include <bits/stdc++.h>
#define min(a,b) (a<b?a:b)
using namespace std;
typedef long long ll;
const int MAXN = 2e5 + 5;
struct Node
{
	ll s, d, e;
};
Node a[MAXN];
ll judge(int n, int x)
{
	ll ans = 0;
	for (int i = 1; i <= n; ++i)
		if (x >= a[i].s)
			ans += (min(x, a[i].e) - a[i].s) / a[i].d + 1;
	return ans;
}
int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		int n;
		scanf("%d", &n);
		for (int i = 1; i <= n; ++i)
			scanf("%lld%lld%lld", &a[i].s, &a[i].e, &a[i].d);
		ll l = 0, r = (1ll << 31);
		ll ans;
		while (l < r)
		{
			ll m = (l + r) >> 1;
			ans = judge(n, m);
			if (ans % 2 == 0)
				l = m + 1;
			else
				r = m;
		}
		if (l == (1ll << 31))
			printf("There's no weakness.\n");
		else
		{
			ans = 0;
			printf("%lld ", l);
			for (int i = 1; i <= n; ++i)
				if (l - a[i].s >= 0 && (l - a[i].s) % a[i].d == 0)
					ans += 1;
			printf("%lld\n", ans);
		}
	}
	return 0;
}