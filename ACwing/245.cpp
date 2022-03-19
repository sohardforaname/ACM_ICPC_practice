#include <bits/stdc++.h>
using namespace std;
const int MAXN = 5e5 + 5;
typedef long long ll;
int a[MAXN];
struct Segtree
{
#define ls (k<<1)
#define rs ((k<<1)+1)
	ll lmax[MAXN << 2], rmax[MAXN << 2], maxn[MAXN << 2], sum[MAXN << 2];
	int l[MAXN << 2], r[MAXN << 2];
	void pushup(int k)
	{
		sum[k] = sum[ls] + sum[rs];
		lmax[k] = max(lmax[ls], sum[ls] + lmax[rs]);
		rmax[k] = max(rmax[rs], sum[rs] + rmax[ls]);
		maxn[k] = max(rmax[ls] + lmax[rs], max(maxn[ls], maxn[rs]));
	}
	void build(int ql, int qr, int k)
	{
		l[k] = ql, r[k] = qr;
		if (ql == qr)
		{
			sum[k] = lmax[k] = rmax[k] = maxn[k] = a[ql];
			return;
		}
		int m = (ql + qr) >> 1;
		build(ql, m, ls);
		build(m + 1, qr, rs);
		pushup(k);
	}
	void update(int pos, int val, int k)
	{
		if (l[k] == r[k])
		{
			sum[k] = maxn[k] = lmax[k] = rmax[k] = val;
			return;
		}
		int m = (l[k] + r[k]) >> 1;
		if (pos <= m)
			update(pos, val, ls);
		else
			update(pos, val, rs);
		pushup(k);
	}
	ll queryl(int ql, int qr, int k)
	{
		if (ql <= l[k] && qr >= r[k])
			return lmax[k];
		ll ans = -0x3f3f3f3f3f3f3f3f;
		int m = (l[k] + r[k]) >> 1;
		if (ql <= m)
			ans = max(ans, queryl(ql, qr, ls));
		if (qr > m)
			ans = max(ans, sum[ls] + queryl(ql, qr, rs));
		return ans;
	}
	ll queryr(int ql, int qr, int k)
	{
		if (ql <= l[k] && qr >= r[k])
			return rmax[k];
		ll ans = -0x3f3f3f3f3f3f3f3f;
		int m = (l[k] + r[k]) >> 1;
		if (ql <= m)
			ans = max(ans, sum[rs] + queryr(ql, qr, ls));
		if (qr > m)
			ans = max(ans, queryr(ql, qr, rs));
		return ans;
	}
	ll query(int ql, int qr, int k)
	{
		if (ql <= l[k] && qr >= r[k])
			return maxn[k];
		ll ans = -0x3f3f3f3f3f3f3f3f;
		int m = (l[k] + r[k]) >> 1;
		if (ql <= m)
			ans = max(ans, query(ql, qr, ls));
		if (qr > m)
			ans = max(ans, query(ql, qr, rs));
		if (ql <= m && qr > m)
			ans = max(ans, queryl(ql, qr, rs) + queryr(ql, qr, ls));
		return ans;
	}
};
Segtree tr;
int main()
{
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; ++i)
		scanf("%d", &a[i]);
	tr.build(1, n, 1);
	int op, x, y;
	for (int i = 1; i <= m; ++i)
	{
		scanf("%d%d%d", &op, &x, &y);
		if (op == 1)
		{
			if (x > y)
				swap(x, y);
			printf("%lld\n", tr.query(x, y, 1));
		}
		else
			tr.update(x, y, 1);
	}
	return 0;
}