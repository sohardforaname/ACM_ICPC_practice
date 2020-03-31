#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 5;
struct BIT
{
	int c[MAXN];
	int lowbit(int x)
	{
		return x & (-x);
	}
	void init()
	{
		memset(c, 0, sizeof(c));
	}
	void update(int pos, int val, int n)
	{
		for (; pos <= n; pos += lowbit(pos))
			c[pos] += val;
	}
	int query(int l, int r)
	{
		int ans1 = 0, ans2 = 0;
		for (l -= 1; l; l -= lowbit(l))
			ans1 += c[l];
		for (r; r; r -= lowbit(r))
			ans2 += c[r];
		return ans2 - ans1;
	}
};
BIT tr;
int a[MAXN], ans[MAXN];
int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 2; i <= n; ++i)
		scanf("%d", &a[i]);
	a[1] = 0;
	tr.init();
	for (int i = 1; i <= n; ++i)
		tr.update(i, 1, n);
	for (int i = n; i; --i)
	{
		int l = 1, r = n;
		while (l < r)
		{
			int m = (l + r) >> 1;
			if (tr.query(1, m) > a[i])
				r = m;
			else
				l = m + 1;
		}
		ans[i] = l;
		tr.update(l, -1, n);
	}
	for (int i = 1; i <= n; ++i)
		printf("%d\n", ans[i]);
	return 0;
}