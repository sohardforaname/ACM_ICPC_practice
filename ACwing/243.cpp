#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN = 1e5 + 5;
struct BIT
{
	ll c[MAXN];
	int lowbit(int x)
	{
		return x & (-x);
	}
	void update(int pos, ll x, int n)
	{
		for (; pos <= n; pos += lowbit(pos))
			c[pos] += x;
	}
	ll sum(int pos)
	{
		ll ans = 0;
		for (; pos; pos -= lowbit(pos))
			ans += c[pos];
		return ans;
	}
	ll query(int l, int r)
	{
		return sum(r) - sum(l - 1);
	}
};
BIT tr1, tr2;
ll a[MAXN], b[MAXN], sum[MAXN];
char op[2];
int main()
{
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; ++i)
	{
		scanf("%lld", &a[i]);
		b[i] = a[i] - a[i - 1];
		sum[i] = sum[i - 1] + a[i];
	}
	ll l, r, x;
	for (int i = 1; i <= m; ++i)
	{
		scanf("%s%lld%lld", op, &l, &r);
		if (op[0] == 'C')
		{
			scanf("%lld", &x);
			tr1.update(l, x, n);//差分序列只有这么修改才会对原序列产生正确的影响
			tr1.update(r + 1, -x, n);
			tr2.update(l, x * l, n);
			tr2.update(r + 1, -x * (r + 1), n);
		}
		else if (op[0] == 'Q')
		{
			ll ans = sum[r] + tr1.query(1, r) * (r + 1) - tr2.query(1, r);
			ans -= sum[l - 1] + tr1.query(1, l - 1) * l - tr2.query(1, l - 1);
			printf("%lld\n", ans);
		}
	}
	return 0;
}