#include <bits/stdc++.h>
using namespace std;
const int MAXN = 5e3 + 5;
struct castle
{
	int a, b, c;
};
castle c[MAXN];
int minn[MAXN];
int fre[MAXN];
int last[MAXN];
priority_queue<pair<int, int> >q;
int main()
{
	int n, m, k;
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 1; i <= n; ++i)
		scanf("%d%d%d", &c[i].a, &c[i].b, &c[i].c), last[i] = i;
	for (int i = 1; i <= m; ++i)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		last[b] = max(last[b], a);
	}
	for (int i = n; i; --i)
		minn[i] = max(c[i + 1].a, minn[i + 1] - c[i + 1].b);
	int now = k;
	for (int i = 1; i <= n; ++i)
	{
		if (now < c[i].a)
			return printf("-1\n"), 0;
		now += c[i].b;
	}
	int cur = k;
	for (int i = 1; i <= n; ++i)
	{
		cur += c[i].b;
		fre[i] = cur - minn[i];//到达n时，已经没有城堡需要攻占，故minn[n]=0
		cur = minn[i];
		q.push(make_pair(c[i].c, i));
	}
	int ans = 0;
	while (!q.empty())
	{
		auto i = q.top();
		q.pop();
		int las = last[i.second];
		while (!fre[las] && las)
			--las;
		assert(las >= 0);
		if (!las)
			continue;
		--fre[las];
		ans += i.first;
	}
	printf("%d\n", ans);
	return 0;
}