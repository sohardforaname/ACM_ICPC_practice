#include <iostream>
#include <cstring>
using namespace std;
#define N 100005
struct TreeArray
{
	int c[N];
	void clean()
	{
		memset(c, 0, sizeof(c));
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
	int query(int x)
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
	int n, m, a, b;
	cin >> n >> m;
	char ch;
	tr.clean();
	for (int i = 0; i < m; ++i)
	{
		cin >> ch >> a >> b;
		if (ch == 'x')
			tr.update(a, b, n);
		else if (ch == 'y')
			cout << tr.query(b) - tr.query(a - 1) << endl;
	}
	return 0;
}