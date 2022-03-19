#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
pair<int, int>p[N << 1];
multiset<int>s;
int cnt[N];
void solve()
{
	int n, l, r;
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i)
	{
		scanf("%d%d", &l, &r);
		p[i * 2 - 1].first = l, p[i * 2 - 1].second = -i;
		p[i << 1].first = r, p[i << 1].second = i;
		cnt[i] = 0;
	}
	sort(p + 1, p + (n << 1) + 1);
	s.clear();
	int ans = 0;
	for (int i = 1; i <= n << 1; ++i)
	{
		if (p[i].second < 0)//左端点
			s.insert(-p[i].second);
		else//右端点
			s.erase(s.find(p[i].second));
		if (s.size() == 0)
			++ans;
		if (s.size() == 1 && p[i].second < 0 && p[i + 1].second > 0)//这个是l，下一个是r
			--cnt[*s.begin()];
		if (s.size() == 1 && p[i].second > 0 && p[i + 1].second < 0 && p[i + 1].first > p[i].first)//这个是r，下个是l
			++cnt[*s.begin()];
	}
	int maxn = -1;
	for (int i = 1; i <= n; ++i)
		maxn = max(maxn, cnt[i]);
	printf("%d\n", ans + maxn);
}
int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
		solve();
	return 0;
}