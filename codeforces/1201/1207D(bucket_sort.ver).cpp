#include<bits/stdc++.h>
using namespace std;
pair<int, int>p[300005];
int num[300005];
long long mul[300005];
const long long mod = 998244353;
void init()
{
	mul[0] = mul[1] = 1;
	for (int i = 2; i <= 300000; ++i)
		mul[i] = (mul[i - 1] * i) % mod;
}
bool check(int n)
{
	for (int i = 2; i <= n; ++i)
		if (p[i].second < p[i - 1].second)
			return 1;
	return 0;
}
long long solve(int n)
{
	sort(p + 1, p + n + 1);
	if (check(n))
		return 0;
	int pos, s;
	long long ans = 1;
	for (int i = 1; i <= n; i = pos)
	{
		for (pos = i; pos <= n && p[i].first == p[pos].first && p[i].second == p[pos].second; ++pos);
		s = pos - i;
		ans = (ans * mul[s]) % mod;
	}
	return ans;
}
long long solve2(int n)
{
	long long ans = 1;
	memset(num, 0, sizeof(num));
	for (int i = 1; i <= n; ++i)
		++num[p[i].first];
	for (int i = 1; i <= n; ++i)
		if (num[i])
			ans = (ans * mul[num[i]]) % mod;
	return ans;
}
long long solve3(int n)
{
	long long ans = 1;
	memset(num, 0, sizeof(num));
	for (int i = 1; i <= n; ++i)
		++num[p[i].second];
	for (int i = 1; i <= n; ++i)
		if (num[i])
			ans = (ans * mul[num[i]]) % mod;
	return ans;
}
int main()
{
	int n;
	init();
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i)
		scanf("%d%d", &p[i].first, &p[i].second);
	long long ans1 = solve(n);
	long long ans2 = solve2(n);
	long long ans3 = solve3(n);
	long long ans = (ans2 + ans3 - ans1 + mod) % mod;
	printf("%lld\n", (mul[n] - ans + mod) % mod);
	return 0;
}
