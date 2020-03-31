#include<bits/stdc++.h>
using namespace std;
#define ls (k<<1)
#define rs (k<<1)+1
const int MAXN = 5e4 + 5;
const int INF = 0x7fffffff;
int num[50005];
struct Treap
{
	struct node
	{
		int val, son[2], size, rnd, num;
	};
	node tr[MAXN << 7];
	int cnt;
	void init()
	{
		cnt = 0;
	}
	int _rand()
	{
		static int seed = 12345;
		return seed = (seed * 482711ll) % INF;
	}
	void update(int& rt)
	{
		tr[rt].size = tr[tr[rt].son[0]].size + tr[tr[rt].son[1]].size + tr[rt].num;
	}
	int newnode(int val)
	{
		int rt = ++cnt;
		tr[rt].val = val;
		tr[rt].son[0] = tr[rt].son[1] = 0;
		tr[rt].size = tr[rt].num = 1;
		tr[rt].rnd = _rand();
		return rt;
	}
	void rotate(int& rt, int c)
	{
		int tmp = tr[rt].son[!c];
		tr[rt].son[!c] = tr[tmp].son[c];
		tr[tmp].son[c] = rt;
		tr[tmp].size = tr[rt].size;
		update(rt);
		rt = tmp;
	}
	void insert(int& rt, int val)
	{
		if (!rt)
		{
			rt = newnode(val);
			return;
		}
		++tr[rt].size;
		if (val == tr[rt].val)
			++tr[rt].num;
		else if (val > tr[rt].val)
		{
			insert(tr[rt].son[1], val);
			if (tr[rt].rnd > tr[tr[rt].son[1]].rnd)
				rotate(rt, 0);
		}
		else if (val < tr[rt].val)
		{
			insert(tr[rt].son[0], val);
			if (tr[rt].rnd > tr[tr[rt].son[0]].rnd)
				rotate(rt, 1);
		}
		update(rt);
	}
	void del(int& rt, int val)
	{
		if (rt == 0)
			return;
		if (tr[rt].val == val)
		{
			if (tr[rt].num > 1)
				--tr[rt].num, --tr[rt].size;
			else
			{
				if (!tr[rt].son[0] || !tr[rt].son[1])
					rt = tr[rt].son[0] + tr[rt].son[1];
				else if (tr[tr[rt].son[0]].rnd < tr[tr[rt].son[1]].rnd)
					rotate(rt, 1), del(rt, val);
				else if (tr[tr[rt].son[0]].rnd > tr[tr[rt].son[1]].rnd)
					rotate(rt, 0), del(rt, val);
			}
		}
		else if (val > tr[rt].val)
			--tr[rt].size, del(tr[rt].son[1], val);
		else
			--tr[rt].size, del(tr[rt].son[0], val);
	}
	int queryrnk(int& rt, int val)
	{
		if (rt == 0)
			return 0;
		else if (tr[rt].val == val)
			return tr[tr[rt].son[0]].size;
		else if (tr[rt].val < val)
			return tr[tr[rt].son[0]].size + tr[rt].num + queryrnk(tr[rt].son[1], val);
		else
			return queryrnk(tr[rt].son[0], val);
	}
	int querynum(int& rt, int rnk)
	{
		if (rt == 0)
			return 0;
		if (rnk <= tr[tr[rt].son[0]].size)
			return querynum(tr[rt].son[0], rnk);
		rnk -= tr[tr[rt].son[0]].size;
		if (rnk <= tr[rt].num)
			return tr[rt].val;
		rnk -= tr[rt].num;
		return querynum(tr[rt].son[1], rnk);
	}
	int queryfront(int& rt, int val)
	{
		if (rt == 0)
			return -INF;
		else if (tr[rt].val < val)
			return max(tr[rt].val, queryfront(tr[rt].son[1], val));
		else
			return queryfront(tr[rt].son[0], val);
	}
	int queryback(int& rt, int val)
	{
		if (rt == 0)
			return INF;
		else if (tr[rt].val > val)
			return min(tr[rt].val, queryback(tr[rt].son[0], val));
		else
			return queryback(tr[rt].son[1], val);
	}
};
Treap tp;
struct Segtree
{
	struct node
	{
		int l, r, root;
	};
	node tr[MAXN << 2];
	void build(int l, int r, int k)
	{
		tr[k].l = l, tr[k].r = r;
		for (int i = tr[k].l; i <= tr[k].r; ++i)
			tp.insert(tr[k].root, num[i]);
		if (l == r)
			return;
		int m = (l + r) >> 1;
		build(l, m, ls);
		build(m + 1, r, rs);
	}
	void update(int pos, int k, int val, int cur)
	{
		tp.del(tr[k].root, cur);
		tp.insert(tr[k].root, val);
		if (tr[k].l == tr[k].r)
			return;
		int m = (tr[k].l + tr[k].r) >> 1;
		if (pos <= m)
			update(pos, ls, val, cur);
		else
			update(pos, rs, val, cur);
	}
	int querynum(int l, int r, int rnk)
	{
		int minn = 0, maxn = 1e8;
		int res = 0, m;
		while (minn < maxn)
		{
			m = (minn + maxn) >> 1;
			res = queryrnk(l, r, 1, m);
			if (res < rnk)
				minn = m + 1;
			else
				maxn = m;
		}
		return minn - 1;
	}
	int queryrnk(int l, int r, int k, int val)
	{
		if (l <= tr[k].l && r >= tr[k].r)
			return tp.queryrnk(tr[k].root, val);
		int ans = 0, m = (tr[k].l + tr[k].r) >> 1;
		if (l <= m)
			ans += queryrnk(l, r, ls, val);
		if (r > m)
			ans += queryrnk(l, r, rs, val);
		return ans;
	}
	int queryfront(int l, int r, int k, int val)
	{
		if (l <= tr[k].l && r >= tr[k].r)
			return tp.queryfront(tr[k].root, val);
		int ans = -INF, m = (tr[k].l + tr[k].r) >> 1;
		if (l <= m)
			ans = max(ans, queryfront(l, r, ls, val));
		if (r > m)
			ans = max(ans, queryfront(l, r, rs, val));
		return ans;
	}
	int queryback(int l, int r, int k, int val)
	{
		if (l <= tr[k].l && r >= tr[k].r)
			return tp.queryback(tr[k].root, val);
		int ans = INF, m = (tr[k].l + tr[k].r) >> 1;
		if (l <= m)
			ans = min(ans, queryback(l, r, ls, val));
		if (r > m)
			ans = min(ans, queryback(l, r, rs, val));
		return ans;
	}
};
Segtree tr;
int main()
{
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; ++i)
		scanf("%d", &num[i]);
	tp.init();
	tr.build(1, n, 1);
	int op, l, r, x;
	for (int i = 0; i < m; ++i)
	{
		scanf("%d", &op);
		if (op == 1)
		{
			scanf("%d%d%d", &l, &r, &x);
			printf("%d\n", tr.queryrnk(l, r, 1, x) + 1);
		}
		else if (op == 2)
		{
			scanf("%d%d%d", &l, &r, &x);
			printf("%d\n", tr.querynum(l, r, x));
		}
		else if (op == 3)
		{
			scanf("%d%d", &l, &x);
			tr.update(l, 1, x, num[l]);
			num[l] = x;
		}
		else if (op == 4)
		{
			scanf("%d%d%d", &l, &r, &x);
			printf("%d\n", tr.queryfront(l, r, 1, x));
		}
		else if (op == 5)
		{
			scanf("%d%d%d", &l, &r, &x);
			printf("%d\n", tr.queryback(l, r, 1, x));
		}
	}
	return 0;
}
