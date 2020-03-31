#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
#define N 500005
struct TreeArray
{
	struct node
	{
		long long val;
		int index;
		bool operator<(node& a)
		{
			if (this->val == a.val)
				return this->index < a.index;
			return this->val < a.val;
		}
	};
	node a[N];
	int c[N];
	int lowbit(int x)
	{
		return x & (-x);
	}
	void update(int x, int n)
	{
		for (int i = x; i <= n; i += lowbit(i))
			++c[i];
	}
	int query(int x)
	{
		int ans = 0;
		for (int i = x; i; i -= lowbit(i))
			ans += c[i];
		return ans;
	}
	long long solve(int n)
	{
		long long ans = 0;
		memset(c, 0, sizeof(c));
		for (int i = 1; i <= n; ++i)
			cin >> a[i].val, a[i].index = i;
		sort(a + 1, a + n + 1);
		for (int i = 1; i <= n; ++i)
		{
			update(a[i].index, n);
			ans += (i - query(a[i].index));
		}
		return ans;
	}
};
TreeArray tr;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	cout << tr.solve(n) << endl;
	return 0;
}