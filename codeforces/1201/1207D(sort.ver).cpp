#include<bits/stdc++.h>
using namespace std;
pair<int, int> sp[300005];
const long long mod = 998244353;
long long mul[300005];
int n;
bool is2bad = 1;
bool cmp1(pair<int, int>& a, pair<int, int>& b)
{
	return a.second < b.second;
}
long long solve()
{
	sort(sp + 1, sp + n + 1);
	for (int i = 2; i <= n; ++i)
		if (sp[i].second < sp[i - 1].second)
			is2bad = 0;
	long long ans = 1;
	if (is2bad)
	{
		int pos, s;
		for (int i = 1; i <= n; i = pos)
		{
			for (pos = i + 1; pos <= n && sp[i].first == sp[pos].first && sp[i].second == sp[pos].second; ++pos);
			s = pos - i;
			ans = ans * mul[s] % mod;
		}
	}
	return ans;
}
long long solve2()
{
	long long ans = 1;
	int pos, s;
	for (int i = 1; i <= n; i = pos)
	{
		for (pos = i + 1; pos <= n && sp[i].first == sp[pos].first; ++pos);
		s = pos - i;
		ans = ans * mul[s] % mod;
	}
	return ans;
}
long long solve3()
{
	long long ans = 1;
	int pos, s;
	sort(sp + 1, sp + n + 1, cmp1);
	for (int i = 1; i <= n; i = pos)
	{
		for (pos = i + 1; pos <= n && sp[i].second == sp[pos].second; ++pos);
		s = pos - i;
		ans = ans * mul[s] % mod;
	}
	return ans;
}
int main()
{
	int a, b;
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i)
	{
		scanf("%d%d", &a, &b);
		sp[i] = make_pair(a, b);
	}

	mul[0] = mul[1] = 1;
	for (int i = 2; i <= n; ++i)
		mul[i] = mul[i - 1] * i % mod;
	long long ans1 = solve(), ans2 = solve2(), ans3 = solve3();
	long long ans = (ans2 + ans3) % mod;
	if (is2bad)
		ans = (ans - ans1 + mod) % mod;
	printf("%lld\n", (mul[n] - ans + mod) % mod);
	return 0;
}
