#include <iostream>
using namespace std;
#define N 100005
long long m;
struct Segtree
{
	struct node
	{
		int l, r;
		long long val, alazy, mlazy;
	}tr[N * 4];
	void build(int l, int r, int k)
	{
		tr[k].l = l, tr[k].r = r, tr[k].alazy = 0, tr[k].mlazy = 1;
		if (l == r)
		{
			cin >> tr[k].val;
			return;
		}
		int mm = (l + r) / 2;
		build(l, mm, k * 2);
		build(mm + 1, r, k * 2 + 1);
		tr[k].val = (tr[k * 2].val + tr[k * 2 + 1].val) % m;
	}
	void down(int k)
	{
		tr[k * 2].mlazy = (tr[k].mlazy * tr[k * 2].mlazy) % m;
		tr[k * 2 + 1].mlazy = (tr[k].mlazy * tr[k * 2 + 1].mlazy) % m;
		tr[k * 2].alazy = (tr[k * 2].alazy * tr[k].mlazy + tr[k].alazy) % m;
		tr[k * 2 + 1].alazy = (tr[k * 2 + 1].alazy * tr[k].mlazy + tr[k].alazy) % m;
		tr[k * 2].val = ((tr[k * 2].val * tr[k].mlazy) % m + (tr[k].alazy * (tr[k * 2].r - tr[k * 2].l + 1)) % m) % m;
		tr[k * 2 + 1].val = ((tr[k * 2 + 1].val * tr[k].mlazy) % m + (tr[k].alazy * (tr[k * 2 + 1].r - tr[k * 2 + 1].l + 1)) % m) % m;
		tr[k].alazy = 0;
		tr[k].mlazy = 1;
	}
	void update(int l, int r, int d, long long val, int k)
	{
		if (l <= tr[k].l && r >= tr[k].r)
		{
			if (d == 2)
			{
				tr[k].alazy = (tr[k].alazy + val) % m;
				tr[k].val = (tr[k].val + val * (tr[k].r - tr[k].l + 1)) % m;
			}
			else if (d == 1)
			{
				tr[k].mlazy = (tr[k].mlazy * val) % m;
				tr[k].alazy = (tr[k].alazy * val) % m;
				tr[k].val = (tr[k].val * val) % m;
			}
			return;
		}
		down(k);
		int mm = (tr[k].l + tr[k].r) / 2;
		if (l <= mm)
			update(l, r, d, val, k * 2);
		if (r >= mm + 1)
			update(l, r, d, val, k * 2 + 1);
		tr[k].val = (tr[k * 2].val + tr[k * 2 + 1].val) % m;
	}
	long long query(int l, int r, int k)
	{
		if (l <= tr[k].l && r >= tr[k].r)
			return tr[k].val;
		down(k);
		long long ans = 0;
		int mm = (tr[k].l + tr[k].r) / 2;
		if (l <= mm)
			ans = (ans + query(l, r, k * 2)) % m;
		if (r >= mm + 1)
			ans = (ans + query(l, r, k * 2 + 1)) % m;
		return ans % m;
	}
};
Segtree seg;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, k, a, b, c;
	long long d;
	cin >> n >> m;
	seg.build(1, n, 1);
	cin >> k;
	for (int i = 0; i < k; ++i)
	{
		cin >> a;
		if (a == 1)
		{
			cin >> b >> c >> d;
			seg.update(b, c, 1, d, 1);
		}
		else if (a == 2)
		{
			cin >> b >> c >> d;
			seg.update(b, c, 2, d, 1);
		}
		else if (a == 3)
		{
			cin >> b >> c;
			cout << seg.query(b, c, 1) << endl;
		}
	}
	return 0;
}