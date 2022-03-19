#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN = 5e5 + 5;
ll a[MAXN];
ll gcd(ll a, ll b)
{
	return b == 0 ? a : gcd(b, a % b);
}
struct BIT
{
	ll c[MAXN];
	int lowbit(int x)
	{
		return x & (-x);
	}
	void update(int pos, ll val, int n)
	{
		for (; pos <= n; pos += lowbit(pos))
			c[pos] += val;
	}
	ll sum(int l)
	{
		ll ans = 0;
		for (; l; l -= lowbit(l))
			ans += c[l];
		return ans;
	}
	ll query(int l, int r)
	{
		return sum(r) - sum(l - 1);
	}
};
struct segtree
{
#define ls (k<<1)
#define rs ((k<<1)+1)
	ll sum[MAXN << 2];
	void pushup(int k)
	{
		sum[k] = gcd(sum[ls], sum[rs]);
	}
	void build(int l, int r, int k)
	{
		if (l == r)
		{
			sum[k] = a[l] - a[l - 1];
			return;
		}
		int m = (l + r) >> 1;
		build(l, m, ls);
		build(m + 1, r, rs);
		pushup(k);
	}
	void update(int ql, int qr, int pos, ll val, int k)
	{
		if (ql == qr)
		{
			sum[k] += val;
			return;
		}
		int m = (ql + qr) >> 1;
		if (pos <= m)
			update(ql, m, pos, val, ls);
		else if (pos > m)
			update(m + 1, qr, pos, val, rs);
		pushup(k);
	}
	ll query(int l, int r, int ql, int qr, int k)
	{
		if (l <= ql && r >= qr)
			return sum[k];
		int m = (ql + qr) >> 1;
		if (r <= m)
			return query(l, r, ql, m, ls);
		else if (l > m)
			return query(l, r, m + 1, qr, rs);
		else
			return gcd(query(l, r, ql, m, ls), query(l, r, m + 1, qr, rs));
	}
};
segtree tr;
BIT bt;
char op[2];
int main()
{
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; ++i)
		scanf("%lld", &a[i]), bt.update(i, a[i] - a[i], n);
	tr.build(1, n, 1);
	int l, r;
	ll x;
	for (int i = 1; i <= m; ++i)
	{
		scanf("%s%d%d", op, &l, &r);
		if (op[0] == 'C')
		{
			scanf("%lld", &x);
			tr.update(1, n, l, x, 1);
			bt.update(l, x, n);
			if (r < n)
			{
				tr.update(1, n, r + 1, -x, 1);
				bt.update(r + 1, -x, n);
			}
		}
		else if (op[0] == 'Q')
			printf("%lld\n", abs(gcd(a[l] + bt.sum(l), tr.query(l + 1, r, 1, n, 1))));
	}
	return 0;
}