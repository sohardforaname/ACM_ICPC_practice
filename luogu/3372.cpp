#include <iostream>
#include <algorithm>
using namespace std;
#define Tree 100005
class Segtree
{
public:
	struct node
	{
		int l, r;
		long long val, lazy;
	};
	node tree[Tree * 4 + 5];
	void build(int l, int r, int k)
	{
		tree[k].l = l, tree[k].r = r;
		if (l == r)
		{
			cin >> tree[k].val, tree[k].lazy = 0;
			return;
		}
		int m = (l + r) / 2;
		build(l, m, k * 2);
		build(m + 1, r, k * 2 + 1);
		tree[k].val = tree[k * 2].val + tree[k * 2 + 1].val;
	}
	long long ask_line(int l, int r, int k)
	{
		if (l <= tree[k].l && r >= tree[k].r)
			return tree[k].val;
		long long ans = 0;
		if (tree[k].lazy)
			down(k);
		int m = (tree[k].l + tree[k].r) / 2;
		if (l <= m)
			ans += ask_line(l, r, k * 2);
		if (r >= m + 1)
			ans += ask_line(l, r, k * 2 + 1);
		return ans;
	}
	void down(int k)
	{
		tree[k * 2].lazy += tree[k].lazy;
		tree[k * 2 + 1].lazy += tree[k].lazy;
		tree[k * 2].val += tree[k].lazy * (tree[k * 2].r - tree[k * 2].l + 1);
		tree[k * 2 + 1].val += tree[k].lazy * (tree[k * 2 + 1].r - tree[k * 2 + 1].l + 1);
		tree[k].lazy = 0;
	}
	void change_line(int l, int r, int k, int val)
	{
		if (l <= tree[k].l && r >= tree[k].r)
		{
			tree[k].val += val * (tree[k].r - tree[k].l + 1);
			tree[k].lazy += val;
			return;
		}
		if (tree[k].lazy)
			down(k);
		int m = (tree[k].l + tree[k].r) / 2;
		if (l <= m)
			change_line(l, r, k * 2, val);
		if (r >= m + 1)
			change_line(l, r, k * 2 + 1, val);
		tree[k].val = tree[k * 2].val + tree[k * 2 + 1].val;
		return;
	}
};
Segtree seg;
int main()
{
	int n, m, a, b, c, d;
	cin >> n >> m;
	seg.build(1, n, 1);
	for (int i = 0; i < m; ++i)
	{
		cin >> a;
		if (a == 1)
		{
			cin >> b >> c >> d;
			seg.change_line(b, c, 1, d);
		}
		else if (a == 2)
		{
			cin >> b >> c;
			cout << seg.ask_line(b, c, 1) << endl;
		}
	}
	return 0;
}