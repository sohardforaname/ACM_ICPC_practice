#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN = 2e5 + 5;
struct BIT
{
	int c[MAXN];
	void init(int n)
	{
		memset(c, 0, sizeof(c[0]) * (n + 1));
	}
	int lowbit(int x)
	{
		return x & (-x);
	}
	void update(int pos, int val, int n)
	{
		for (pos; pos <= n; pos += lowbit(pos))
			c[pos] += val;
	}
	int sum(int pos)
	{
		int ans = 0;
		for (pos; pos; pos -= lowbit(pos))
			ans += c[pos];
		return ans;
	}
	int query(int l, int r)
	{
		return sum(r) - sum(l - 1);
	}
};
BIT tr;
int a[MAXN], l[MAXN], r[MAXN];
int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i)
		scanf("%d", &a[i]);
	ll ans1 = 0, ans2 = 0;
	tr.init(n);
	for (int i = n; i; --i)
	{
		r[i] = tr.query(a[i] + 1, n);
		tr.update(a[i], 1, n);
	}
	tr.init(n);
	for (int i = 1; i <= n; ++i)
	{
		l[i] = tr.query(a[i] + 1, n);
		tr.update(a[i], 1, n);
	}
	for (int i = 1; i <= n; ++i)
	{
		ans1 += l[i] * ll(r[i]);
		ans2 += (i - 1ll - l[i]) * (n - i - r[i]);
	}
	printf("%lld %lld\n", ans1, ans2);
	return 0;
}