#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int cnt[65];
int solve()
{
	memset(cnt, 0, sizeof(cnt));
	ll n, sum = 0;
	int m, a;
	scanf("%lld%d", &n, &m);
	for (int i = 1; i <= m; ++i)
	{
		scanf("%d", &a);
		sum += a;
		int tmp = 0;
		while (a > 1)
			++tmp, a >>= 1;
		++cnt[tmp];
	}
	if (sum < n)
		return printf("-1\n"), 0;
	int ans = 0;
	for (int i = 0; i <= 63; ++i)
	{
		int x = (n >> i) & 1;
		cnt[i] -= x;
		if (cnt[i] >= 2)
			cnt[i + 1] += cnt[i] / 2, cnt[i] -= (cnt[i] / 2) * 2;
		if (cnt[i] < 0)
			--cnt[i + 1], ++ans;
	}
	return printf("%d\n", ans), 0;
}
int main()
{
	int t;
	scanf("%d", &t);
	while (t--)
		solve();
	return 0;
}