#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e4 + 5;
int c[MAXN], d[MAXN];
map<pair<int, int>, int>mp;
int main()
{
	int n, p, h, m, a, b;
	scanf("%d%d%d%d", &n, &p, &h, &m);
	for (int i = 1; i <= m; ++i)
	{
		scanf("%d%d", &a, &b);
		if (a > b)
			swap(a, b);
		++mp[make_pair(a, b)];
	}
	for (auto i : mp)
	{
		d[i.first.first + 1] -= 1;
		d[i.first.second] += 1;
	}
	for (int i = 1; i <= n; ++i)
		c[i] = c[i - 1] + d[i];
	for (int i = 1; i <= n; ++i)
		printf("%d\n", h + c[i]);
	return 0;
}
