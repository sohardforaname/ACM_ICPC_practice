#include <iostream>
#include <cstring>
using namespace std;
#define Tree 100005
struct Segtree
{
	struct node
	{
		int l, r;
		long long val, lazy;
	}tree[Tree * 4];
	void clean()
	{
		memset(tree, 0, sizeof(tree));
	}
	void build(int l, int r, int k)
	{
		tree[k].l = l, tree[k].r = r, tree[k].lazy = 0;
		if (l == r)
		{
			tree[k].val = 1;
			return;
		}
		int m = (l + r) / 2;
		build(l, m, k * 2);
		build(m + 1, r, k * 2 + 1);
		tree[k].val = tree[k * 2].val + tree[k * 2 + 1].val;
	}
	void down(int k)
	{
		tree[k * 2].lazy = tree[k].lazy;
		tree[k * 2 + 1].lazy = tree[k].lazy;
		tree[k * 2].val = tree[k].lazy * (tree[k * 2].r - tree[k * 2].l + 1);
		tree[k * 2 + 1].val = tree[k].lazy * (tree[k * 2 + 1].r - tree[k * 2 + 1].l + 1);
		tree[k].lazy = 0;
	}
	long long ask(int l, int r, int k)
	{
		if (l <= tree[k].l && r >= tree[k].r)
			return tree[k].val;
		if (tree[k].lazy)
			down(k);
		long long ans = 0;
		int m = (tree[k].l + tree[k].r) / 2;
		if (l <= m)
			ans += ask(l, r, k * 2);
		if (r >= m + 1)
			ans += ask(l, r, k * 2 + 1);
		return ans;
	}
	void change(int l, int r, int k, long long val)
	{
		if (l <= tree[k].l && r >= tree[k].r)
		{
			tree[k].lazy = val;
			tree[k].val = val * (tree[k].r - tree[k].l + 1);
			return;
		}
		if (tree[k].lazy)
			down(k);
		int m = (tree[k].l + tree[k].r) / 2;
		if (l <= m)
			change(l, r, k * 2, val);
		if (r >= m + 1)
			change(l, r, k * 2 + 1, val);
		tree[k].val = tree[k * 2].val + tree[k * 2 + 1].val;
	}
};
Segtree seg;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t, n, m, a, b, c;
	cin >> t;
	for (int i = 0; i < t; ++i)
	{
		cin >> n >> m;
		seg.clean();
		seg.build(1, n, 1);
		for (int j = 0; j < m; ++j)
		{
			cin >> a >> b >> c;
			seg.change(a, b, 1, c);
		}
		cout << "Case " << i + 1 << ": The total value of the hook is ";
		cout << seg.ask(1, n, 1) << '.' << endl;
	}
	return 0;
}