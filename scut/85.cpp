#include <bits/stdc++.h>
using namespace std;
const int MAXN = 5e5 + 5;
typedef long long ll;
ll mod = 1008610010;
ll a[MAXN];
struct Segtree
{
	ll sum[MAXN], per[MAXN], lazy[MAXN];
#define ls (k<<1)
#define rs ((k<<1)+1)
	inline void pushup1(int k)
	{
		sum[k] = (sum[ls] + sum[rs]) % mod;
	}
	inline void pushup2(int k)
	{
		per[k] = (per[ls] + per[rs]) % mod;
	}
	inline void pushdown(int k)
	{
		lazy[ls] = (lazy[ls] + lazy[k]) % mod;
		lazy[rs] = (lazy[rs] + lazy[k]) % mod;
		sum[ls] = (sum[ls] + per[ls] * lazy[k] % mod) % mod;
		sum[rs] = (sum[rs] + per[rs] * lazy[k] % mod) % mod;
		lazy[k] = 0;
	}
	void build(int l, int r, int k)
	{
		lazy[k] = 0, sum[k] = 0;
		if (l == r)
		{
			per[k] = a[l];
			return;
		}
		int m = (l + r) >> 1;
		build(l, m, ls);
		build(m + 1, r, rs);
		pushup2(k);
	}
	void update(int l, int r, int ql, int qr, int k, ll v)
	{
		if (l <= ql && r >= qr)
		{
			lazy[k] = (lazy[k] + v) % mod;
			sum[k] = (sum[k] + per[k] * v % mod) % mod;
			return;
		}
		pushdown(k);
		int qm = (ql + qr) >> 1;
		if (l <= qm)
			update(l, r, ql, qm, ls, v);
		if (r > qm)
			update(l, r, qm + 1, qr, rs, v);
		pushup1(k);
	}
	ll query(int l, int r, int ql, int qr, int k)
	{
		if (l <= ql && r >= qr)
			return sum[k] % mod;
		pushdown(k);
		ll ans = 0;
		int qm = (ql + qr) >> 1;
		if (l <= qm)
			ans = (ans + query(l, r, ql, qm, ls)) % mod;
		if (r > qm)
			ans = (ans + query(l, r, qm + 1, qr, rs)) % mod;
		return ans % mod;
	}
};
Segtree tr;
int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i)
		scanf("%lld", &a[i]);
	tr.build(1, n, 1);
	int m;
	scanf("%d", &m);
	int op, l, r;
	ll val;
	for (int i = 1; i <= m; ++i)
	{
		scanf("%d%d%d", &op, &l, &r);
		if (op == 1)
		{
			scanf("%lld", &val);
			tr.update(l, r, 1, n, 1, val);
		}
		else
			printf("%lld\n", tr.query(l, r, 1, n, 1));
	}
	return 0;
}