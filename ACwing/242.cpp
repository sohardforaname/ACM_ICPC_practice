#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN = 1e5 + 5;
struct BIT
{
	int c[MAXN];
	int lowbit(int x)
	{
		return x & (-x);
	}
	void update(int pos, int val, int n)
	{
		for (; pos <= n; pos += lowbit(pos))
			c[pos] += val;
	}
	ll sum(int pos)
	{
		ll ans = 0;
		for (; pos; pos -= lowbit(pos))
			ans += c[pos];
		return ans;
	}
	ll query(int l, int r)
	{
		return sum(r) - sum(l - 1);
	}
};
BIT tr;
int a[MAXN], b[MAXN];
char op[2];
int main()
{
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; ++i)
		scanf("%d", &a[i]), b[i] = a[i] - a[i - 1];
	int x, y, v;
	for (int i = 1; i <= m; ++i)
	{
		scanf("%s%d", op, &x);
		if (op[0] == 'C')
		{
			scanf("%d%d", &y, &v);
			tr.update(x, v, n);
			tr.update(y + 1, -v, n);
		}
		else if (op[0] == 'Q')
			printf("%lld\n", tr.query(1, x) + a[x]);
	}
	return 0;
}