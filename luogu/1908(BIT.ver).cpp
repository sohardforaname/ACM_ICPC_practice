#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
struct TreeArray
{
	struct node
	{
		int val, index;
		bool operator<(const node& a)const
		{
			if (this->val == a.val)
				return this->index < a.index;
			return this->val < a.val;
		}
	};
	int lowbit(int x)
	{
		return x & (-x);
	}
	node a[500005];
	int c[500005];
	long long build(int n)
	{
		for (int i = 1; i <= n; ++i)
			cin >> a[i].val, a[i].index = i;
		sort(a + 1, a + n + 1);
		long long ans = 0;
		for (int i = 1; i <= n; ++i)
			update(a[i].index, n), ans += i - query(a[i].index);
		return ans;
	}
	void update(int x, int n)
	{
		for (int i = x; i <= n; i += lowbit(i))
			++c[i];
	}
	int query(int x)
	{
		int sum = 0;
		for (int i = x; i; i -= lowbit(i))
			sum += c[i];
		return sum;
	}
};
TreeArray tr;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	long long ans = tr.build(n);
	cout << ans << endl;
	return 0;
}
