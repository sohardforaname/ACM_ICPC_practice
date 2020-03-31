#include <iostream>
#include <cstring>
using namespace std;
#define N 500005
struct TreeArray
{
	int a[N], c[N];//Original,New
	void build(int n)
	{
		for (int i = 1; i <= n; ++i)
			cin >> a[i];
		memset(c, 0, sizeof(c));
		for (int i = 1; i <= n; ++i)
			update(i, a[i], n);
	}
	int lowbit(int x)
	{
		return x & (-x);
	}
	int query(int x)
	{
		int ans = 0;
		for (int i = x; i; i -= lowbit(i))
			ans += c[i];
		return ans;
	}
	void update(int x, int val, int n)
	{
		for (int i = x; i <= n; i += lowbit(i))
			c[i] += val;
	}
};
TreeArray tr;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, m, a, b, c;
	cin >> n >> m;
	tr.build(n);
	for (int i = 0; i < m; ++i)
	{
		cin >> a >> b >> c;
		if (a == 1)
			tr.update(b, c, n);
		else
			cout << tr.query(c) - tr.query(b - 1) << endl;
	}
	return 0;
}