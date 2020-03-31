#include <bits/stdc++.h>
using namespace std;
const int MAXN = 5e5 + 5;
struct chieftree
{
	struct node
	{
		int ls, rs, sum;
	};
	node tr[MAXN << 4];
	int root[MAXN], cnt;
	int lsz, rsz;
	void init()
	{
		cnt = 0;
		memset(root, 0, sizeof(root));
		memset(tr, 0, sizeof(tr));
	}
	void update(int l, int r, int &rt, int val, int pos)
	{
		if (!rt)
			rt = ++cnt;
		tr[rt].sum += val;
		if (l == r)
			return;
		int m = (l + r) >> 1;
		if (pos <= m)
			update(l, m, tr[rt].ls, val, pos);
		else
			update(m + 1, r, tr[rt].rs, val, pos);
	}
	int query(int l, int r, int *lset, int *rset, int k)
	{
		if (l == r)
			return l;
		int lsum = 0, rsum = 0;
		for (int i = 0; i < lsz; ++i)
			lsum += tr[tr[lset[i]].ls].sum;
		for (int i = 0; i < rsz; ++i)
			rsum += tr[tr[rset[i]].ls].sum;
		int m = (l + r) >> 1;
		if (rsum - lsum >= k)
		{
			for (int i = 0; i < lsz; ++i)
				lset[i] = tr[lset[i]].ls;
			for (int i = 0; i < rsz; ++i)
				rset[i] = tr[rset[i]].ls;
			return query(l, m, lset, rset, k);
		}
		else
		{
			for (int i = 0; i < lsz; ++i)
				lset[i] = tr[lset[i]].rs;
			for (int i = 0; i < rsz; ++i)
				rset[i] = tr[rset[i]].rs;
			return query(m + 1, r, lset, rset, k - (rsum - lsum));
		}
	}
};
struct BIT
{
	chieftree tr;
	int lset[20], rset[20];
	int lowbit(int x)
	{
		return x & (-x);
	}
	void update(int val, int pos, int rnk, int n, int sz)
	{
		for (int i = pos; i <= n; i += lowbit(i))
			tr.update(1, sz, tr.root[i], val, rnk);
	}
	int query(int ql, int qr, int l, int r, int k)
	{
		--ql;
		tr.lsz = tr.rsz = 0;
		for (int i = ql; i; i -= lowbit(i))
			lset[tr.lsz++] = tr.root[i];
		for (int i = qr; i; i -= lowbit(i))
			rset[tr.rsz++] = tr.root[i];
		return tr.query(l, r, lset, rset, k);
	}
};
BIT btr;
struct ope
{
	int l, r, k;
};
ope s[MAXN];
int num[MAXN], b[MAXN << 1], top, sz;
void init()
{
	top = 0;
	btr.tr.init();
}
void getID()
{
	sort(b, b + top);
	sz = unique(b, b + top) - b;
}
int main()
{
	int T;
	int n, m;
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d%d", &n, &m);
		init();
		for (int i = 1; i <= n; ++i)
			scanf("%d", &num[i]), b[top++] = num[i];
		char str[5];
		for (int i = 1; i <= m; ++i)
		{
			scanf("%s%d%d", str, &s[i].l, &s[i].r);
			if (str[0] == 'C')
				s[i].k = -1, b[top++] = s[i].r;
			else if (str[0] == 'Q')
				scanf("%d", &s[i].k);
		}
		getID();
		for (int i = 1; i <= n; ++i)
		{
			int pos = lower_bound(b, b + sz, num[i]) - b + 1;
			btr.update(1, i, pos, n, sz);
		}
		for (int i = 1; i <= m; ++i)
		{
			if (s[i].k == -1)
			{
				int pos = lower_bound(b, b + sz, num[s[i].l]) - b + 1;
				btr.update(-1, s[i].l, pos, n, sz);
				num[s[i].l] = s[i].r;
				pos = lower_bound(b, b + sz, num[s[i].l]) - b + 1;
				btr.update(1, s[i].l, pos, n, sz);
			}
			else
				printf("%d\n", b[btr.query(s[i].l, s[i].r, 1, sz, s[i].k) - 1]);
		}
	}
	return 0;
}
