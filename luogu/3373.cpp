#include <iostream>
#include <algorithm>
using namespace std;
#define Tree 100005
long long m;
int d;
class Segtree
{
public:
	struct node
	{
		int l, r;
		long long val, alazy, mlazy;
	}tree[Tree * 4 + 5];
	void build(int l, int r, int k)
	{
		tree[k].l = l, tree[k].r = r, tree[k].alazy = 0, tree[k].mlazy = 1;
		if (l == r)
		{
			cin >> tree[k].val;
			return;
		}
		int mm = (l + r) / 2;
		build(l, mm, k * 2);
		build(mm + 1, r, k * 2 + 1);
		tree[k].val = (tree[k * 2].val + tree[k * 2 + 1].val) % m;
	}
	void down(int k)
	{
		tree[k * 2].mlazy = (tree[k * 2].mlazy * tree[k].mlazy) % m;
		tree[k * 2 + 1].mlazy = (tree[k * 2 + 1].mlazy * tree[k].mlazy) % m;
		tree[k * 2].alazy = (tree[k * 2].alazy * tree[k].mlazy + tree[k].alazy) % m;
		tree[k * 2 + 1].alazy = (tree[k * 2 + 1].alazy * tree[k].mlazy + tree[k].alazy) % m;
		tree[k * 2].val = (tree[k].mlazy * tree[k * 2].val + tree[k].alazy * (tree[k * 2].r - tree[k * 2].l + 1)) % m;
		tree[k * 2 + 1].val = (tree[k].mlazy * tree[k * 2 + 1].val + tree[k].alazy * (tree[k * 2 + 1].r - tree[k * 2 + 1].l + 1)) % m;
		tree[k].alazy = 0;
		tree[k].mlazy = 1;
	}
	long long ask(int l, int r, int k)
	{
		if (l <= tree[k].l && r >= tree[k].r)
			return tree[k].val;
		down(k);
		long long ans = 0;
		int mm = (tree[k].l + tree[k].r) / 2;
		if (r >= mm + 1)
			ans = (ans + ask(l, r, k * 2 + 1)) % m;
		if (l <= mm)
			ans = (ans + ask(l, r, k * 2)) % m;
		return ans;
	}
	void change(int l, int r, int k, long long val)
	{
		if (l <= tree[k].l && r >= tree[k].r)
		{
			if (d == 1)
			{
				tree[k].mlazy = (tree[k].mlazy * val) % m;
				tree[k].alazy = (tree[k].alazy * val) % m;
				tree[k].val = (tree[k].val * val) % m;
			}
			else
			{
				tree[k].alazy = (tree[k].alazy + val) % m;
				tree[k].val = (tree[k].val + val * (tree[k].r - tree[k].l + 1)) % m;
			}
			return;
		}
		down(k);
		int mm = (tree[k].l + tree[k].r) / 2;
		if (l <= mm)
			change(l, r, k * 2, val);
		if (r >= mm + 1)
			change(l, r, k * 2 + 1, val);
		tree[k].val = (tree[k * 2].val + tree[k * 2 + 1].val) % m;
	}
};
Segtree seg;
int main()
{
	int n, k;
	cin >> n >> k >> m;
	int x, y;
	long long ss;
	seg.build(1, n, 1);
	for (int i = 0; i < k; ++i)
	{
		cin >> d;
		if (d == 1)
		{
			cin >> x >> y >> ss;
			seg.change(x, y, 1, ss);
		}
		else if (d == 2)
		{
			cin >> x >> y >> ss;
			seg.change(x, y, 1, ss);
		}
		else
		{
			cin >> x >> y;
			cout << seg.ask(x, y, 1) % m << endl;
		}
	}
	return 0;
}
