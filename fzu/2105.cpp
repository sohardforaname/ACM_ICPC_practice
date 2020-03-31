#include <cstdio>
const int MAXN = 1e6 + 5;
const int MAXM = 1e5 + 5;
char a[MAXN];
struct segtree
{
#define ls (k<<1)
#define rs ((k<<1)+1)
	struct node
	{
		int sum;
		char lazy;
	};
	node tr[MAXN << 2];
	void pushup(int k)
	{
		tr[k].sum = tr[ls].sum + tr[rs].sum;
	}
	void xorsolve(int k, int l, int r)
	{
		if (tr[k].lazy == 0)
		{
			tr[k].lazy = 1;
			tr[k].sum = r - l + 1 - tr[k].sum;
		}
		else if (tr[k].lazy == 1)
		{
			tr[k].lazy = 0;
			tr[k].sum = r - l + 1 - tr[k].sum;
		}
		else if (tr[k].lazy == 2)
		{
			tr[k].lazy = 3;
			tr[k].sum = 0;
		}
		else if (tr[k].lazy == 3)
		{
			tr[k].lazy = 2;
			tr[k].sum = r - l + 1;
		}
	}
	void pushdown(int k, int l, int r)
	{
		int m = (l + r) >> 1;
		if (tr[k].lazy == 1)//xor
		{
			xorsolve(ls, l, m);
			xorsolve(rs, m + 1, r);
			tr[k].lazy = 0;
		}
		else if (tr[k].lazy == 2)//or
		{
			tr[ls].lazy = tr[rs].lazy = 2;
			tr[ls].sum = m - l + 1;
			tr[rs].sum = r - m;
			tr[k].lazy = 0;
		}
		else if (tr[k].lazy == 3)//and
		{
			tr[ls].lazy = tr[rs].lazy = 3;
			tr[ls].sum = 0;
			tr[rs].sum = 0;
			tr[k].lazy = 0;
		}
	}
	void build(int l, int r, int k, int index)
	{
		tr[k].lazy = 0;
		if (l == r)
		{
			tr[k].sum = (a[l] & (1 << index)) ? 1 : 0;
			return;
		}
		int m = (l + r) >> 1;
		build(l, m, ls, index);
		build(m + 1, r, rs, index);
		pushup(k);
	}
	void update(int l, int r, int ql, int qr, int k, int val, int tag)
	{
		if (ql != qr)
			pushdown(k, ql, qr);
		if (l <= ql && r >= qr)
		{
			if (val == 1 && tag == 1)//xor
			{
				tr[k].lazy = 1;
				tr[k].sum = qr - ql + 1 - tr[k].sum;//È¡·´
			}
			else if (val == 1 && tag == 2)//or
			{
				tr[k].lazy = 2;
				tr[k].sum = qr - ql + 1;
			}
			else if (val == 0 && tag == 3)//and
			{
				tr[k].lazy = 3;
				tr[k].sum = 0;
			}
			return;
		}
		int m = (ql + qr) >> 1;
		if (l <= m)
			update(l, r, ql, m, ls, val, tag);
		if (r > m)
			update(l, r, m + 1, qr, rs, val, tag);
		pushup(k);
	}
	int query(int l, int r, int ql, int qr, int k)
	{
		if (l <= ql && r >= qr)
			return tr[k].sum;
		pushdown(k, ql, qr);
		int ans = 0, m = (ql + qr) >> 1;
		if (l <= m)
			ans += query(l, r, ql, m, ls);
		if (r > m)
			ans += query(l, r, m + 1, qr, rs);
		return ans;
	}
};
segtree tr[5];
int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		int n, m;
		scanf("%d%d", &n, &m);
		for (int i = 1; i <= n; ++i)
			scanf("%d", &a[i]);
		char ch[5];
		for (int i = 0; i < 4; ++i)
			tr[i].build(1, n, 1, i);
		int l, r, c;
		for (int i = 0; i < m; ++i)
		{
			scanf("%s%d%d", &ch, &c, &l);
			if (ch[0] == 'S')
			{
				long long ans = 0;
				++c, ++l;
				for (int j = 0; j < 4; ++j)
					ans += tr[j].query(c, l, 1, n, 1) * (1ll << j);
				printf("%lld\n", ans);
			}
			else if (ch[0] == 'X')
			{
				scanf("%d", &r);
				++l, ++r;
				for (int j = 0; j < 4; ++j)
					tr[j].update(l, r, 1, n, 1, (c & (1 << j)) ? 1 : 0, 1);
			}
			else if (ch[0] == 'O')
			{
				scanf("%d", &r);
				++l, ++r;
				for (int j = 0; j < 4; ++j)
					tr[j].update(l, r, 1, n, 1, (c & (1 << j)) ? 1 : 0, 2);
			}
			else if (ch[0] == 'A')
			{
				scanf("%d", &r);
				++l, ++r;
				for (int j = 0; j < 4; ++j)
					tr[j].update(l, r, 1, n, 1, (c & (1 << j)) ? 1 : 0, 3);
			}
		}
	}
	return 0;
}
