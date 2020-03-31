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
	void update(int val, int pos, int n)
	{
		for (int i = pos; i <= n; i += lowbit(i))
			c[i] += val;
	}
	long long query(int pos)
	{
		int ans = 0;
		for (int i = pos; i; i -= lowbit(i))
			ans += c[i];
		return ans;
	}
};
BIT tr;
vector<int>num[MAXN];
int main()
{
	int n, a;
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i)
	{
		scanf("%d", &a);
		num[a].push_back(i);
		tr.update(1, i, n);
	}
	long long res = n, ans = 0;
	for (int i = 1; i < MAXN; ++i)
	{
		if (num[i].empty())
			continue;
		for (int j = 0; j < num[i].size(); ++j)
		{
			tr.update(-1, num[i][j], n);
			--res;
		}
		for (int j = 0; j < num[i].size(); ++j)
			ans += min(res - tr.query(num[i][j]), tr.query(num[i][j] - 1));
	}
	printf("%lld\n", ans);
	return 0;
} 
