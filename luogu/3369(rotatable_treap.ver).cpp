#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100005;
const int inf = 0x3f3f3f3f;
struct Treap
{
	struct node
	{
		int val, rnd, son[2], size, num;
	};
	int cnt = 0;
	node tr[MAXN];
	void init()
	{
		cnt = 0;
	}
	int _rand()
	{
		static int seed = 12345;
		return seed = (int)seed * 482711LL % 2147483647;
	}
	void pushup(int p)
	{
		tr[p].size = tr[tr[p].son[0]].size + tr[tr[p].son[1]].size + tr[p].num;
	}
	void rotate(int& k, int c)
	{
		int tmp = tr[k].son[!c];
		tr[k].son[!c] = tr[tmp].son[c];
		tr[tmp].son[c] = k;
		tr[tmp].size = tr[k].size;
		pushup(k);
		k = tmp;
	}
	void insert(int& p, int x)
	{
		if (p == 0)
		{
			p = ++cnt;
			tr[p].val = x;
			tr[p].num = tr[p].size = 1;
			tr[p].son[0] = tr[p].son[1] = 0;
			tr[p].rnd = _rand();
			return;
		}
		++tr[p].size;
		if (x == tr[p].val)
			++tr[p].num;
		else if (x < tr[p].val)
		{
			insert(tr[p].son[0], x);
			if (tr[tr[p].son[0]].rnd < tr[p].rnd)
				rotate(p, 1);
		}
		else if (x > tr[p].val)
		{
			insert(tr[p].son[1], x);
			if (tr[tr[p].son[1]].rnd < tr[p].rnd)
				rotate(p, 0);
		}
	}
	void del(int& p, int x)
	{
		if (p == 0)
			return;
		if (tr[p].val == x)
		{
			if (tr[p].num > 1)
				--tr[p].num, --tr[p].size;
			else
			{
				if (tr[p].son[0] == 0 || tr[p].son[1] == 0)
					p = tr[p].son[0] + tr[p].son[1];
				else if (tr[tr[p].son[0]].rnd < tr[tr[p].son[1]].rnd)
					rotate(p, 1), del(p, x);
				else if (tr[tr[p].son[0]].rnd > tr[tr[p].son[1]].rnd)
					rotate(p, 0), del(p, x);
			}
		}
		else if (tr[p].val < x)
			--tr[p].size, del(tr[p].son[1], x);
		else
			--tr[p].size, del(tr[p].son[0], x);
	}
	int queryrnk(int& p, int x)
	{
		if (p == 0)
			return 0;
		else if (tr[p].val == x)
			return tr[tr[p].son[0]].size;
		else if (tr[p].val < x)
			return tr[tr[p].son[0]].size + tr[p].num + queryrnk(tr[p].son[1], x);
		else
			return queryrnk(tr[p].son[0], x);
	}
	int querynum(int& p, int rnk)
	{
		if (p == 0)
			return 0;
		if (tr[tr[p].son[0]].size >= rnk)
			return querynum(tr[p].son[0], rnk);
		rnk -= tr[tr[p].son[0]].size;
		if (rnk <= tr[p].num)
			return tr[p].val;
		rnk -= tr[p].num;
		return querynum(tr[p].son[1], rnk);
	}
	int queryfront(int& p, int x)
	{
		if (p == 0)
			return -inf;
		if (tr[p].val < x)
			return max(tr[p].val, queryfront(tr[p].son[1], x));
		else if (tr[p].val >= x)
			return queryfront(tr[p].son[0], x);
	}
	int queryback(int& p, int x)
	{
		if (p == 0)
			return inf;
		if (tr[p].val > x)
			return min(tr[p].val, queryback(tr[p].son[0], x));
		else if (tr[p].val <= x)
			return queryback(tr[p].son[1], x);
	}
};
int pos;
Treap tr;
int main()
{
	int n;
	scanf("%d", &n);
	int m, k;
	tr.init();
	for (int i = 0; i < n; ++i)
	{
		scanf("%d%d", &m, &k);
		if (m == 1)
			tr.insert(pos, k);
		else if (m == 2)
			tr.del(pos, k);
		else if (m == 3)
			printf("%d\n", tr.queryrnk(pos, k) + 1);
		else if (m == 4)
			printf("%d\n", tr.querynum(pos, k));
		else if (m == 5)
			printf("%d\n", tr.queryfront(pos, k));
		else if (m == 6)
			printf("%d\n", tr.queryback(pos, k));
	}
	return 0;
}
