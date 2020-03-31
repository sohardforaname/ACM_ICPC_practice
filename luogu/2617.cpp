#include <bits/stdc++.h>
using namespace std;
const int MAXN = 200005;
struct chieftree
{
	struct node
	{
		int ls, rs, sum;
	};
	node tr[MAXN << 6];
	int lsz, rsz;
	int root[MAXN], cnt = 0;
	void init()
	{
		cnt = 0;
		tr[0].ls = tr[0].rs = tr[0].sum = 0;
		root[0] = 0;
	}
	void update(int l, int r, int& rt, int pos, int val)//权值范围，树根，值，位置
	{
		if (!rt)
			rt = ++cnt;
		tr[rt].sum += val;
		if (l == r)
			return;
		int m = (l + r) >> 1;
		if (pos <= m)
			update(l, m, tr[rt].ls, pos, val);
		else
			update(m + 1, r, tr[rt].rs, pos, val);
	}
	int query(int l, int r, int* lset, int* rset, int k)
		//l和r指输入的数据范围，k指第k小
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
	int lset[30], rset[30];
	int lowbit(int x)
	{
		return x & (-x);
	}
	void update(int x, int pos, int rnk, int sz, int n)
	{
		for (int i = pos; i <= n; i += lowbit(i))
			tr.update(1, sz, tr.root[i], rnk, x);
	}
	int query(int beg, int end, int l, int r, int k)
		//beg和end指区间大小，k指第k小
	{
		--beg;
		tr.lsz = tr.rsz = 0;
		for (int i = beg; i; i -= lowbit(i))
			lset[tr.lsz++] = tr.root[i];
		for (int i = end; i; i -= lowbit(i))
			rset[tr.rsz++] = tr.root[i];
		return tr.query(l, r, lset, rset, k);
	}
};
BIT btr;
struct ope
{
	int l, r, k;
};
ope s[MAXN >> 1];
int num[MAXN >> 1], b[MAXN], top, sz;
void getID()
{
	sort(b, b + top);
	sz = unique(b, b + top) - b;
}
int main()
{
	int n, m;
	scanf("%d%d", &n, &m);
	top = 0;
	for (int i = 1; i <= n; ++i)
		scanf("%d", &num[i]), b[top++] = num[i];
	char str[5];
	for (int i = 1; i <= m; ++i)
	{
		scanf("%s%d%d", &str, &s[i].l, &s[i].r);
		if (str[0] == 'Q')
			scanf("%d", &s[i].k);
		else if (str[0] == 'C')
		{
			s[i].k = -1;
			b[top++] = s[i].r;
		}
	}
	getID();
	for (int i = 1; i <= n; ++i)
	{
		int pos = lower_bound(b, b + sz, num[i]) - b + 1;
		btr.update(1, i, pos, sz, n);
	}
	for (int i = 1; i <= m; ++i)
	{
		if (s[i].k == -1)//change
		{
			int pos = lower_bound(b, b + sz, num[s[i].l]) - b + 1;
			btr.update(-1, s[i].l, pos, sz, n);
			num[s[i].l] = s[i].r;
			pos = lower_bound(b, b + sz, s[i].r) - b + 1;
			btr.update(1, s[i].l, pos, sz, n);
		}
		else
			printf("%d\n", b[btr.query(s[i].l, s[i].r, 1, sz, s[i].k) - 1]);
	}
	return 0;
}
