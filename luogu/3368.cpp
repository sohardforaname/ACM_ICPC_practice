#include <iostream>
#include <cstring>
using namespace std;
#define N 500005
struct TreeArray
{
	int a[N], c[N], d[N];
	void build(int n)
	{
		memset(a, 0, sizeof(a));
		memset(c, 0, sizeof(c));
		memset(d, 0, sizeof(d));
		for (int i = 1; i <= n; ++i)
			cin >> a[i];
		for (int i = 1; i <= n; ++i)
			update_range(i, a[i] - a[i - 1], n);
		for (int i = 1; i <= n; ++i)
			update(i, a[i], n);
	}
	int lowbit(int x)
	{
		return x & (-x);
	}
	void update(int x, int val, int n)
	{
		for (int i = x; i <= n; i += lowbit(i))
			c[i] += val;
	}
	void update_range(int l, int val, int n)
	{
		for (int i = l; i <= n; i += lowbit(i))
			d[i] += val;
	}
	int ask(int x)
	{
		int ans = 0;
		for (int i = x; i; i -= lowbit(i))
			ans += d[i];
		return ans;
	}
	int ask_range(int x)
	{
		int ans = 0;
		for (int i = x; i; i -= lowbit(i))
			ans += c[i];
		return ans;
	}
};
TreeArray tr;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, m, a, b, c, d;
	cin >> n >> m;
	tr.build(n);
	for (int i = 0; i < m; ++i)
	{
		cin >> a;
		if (a == 1)
		{
			cin >> b >> c >> d;
			tr.update_range(b, d, n);
			tr.update_range(c + 1, -d, n);
		}
		else
		{
			cin >> b;
			cout << tr.ask(b) << endl;
		}
	}
	return 0;
}
