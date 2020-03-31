#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 5;
int p[MAXN], q[MAXN];
set<int>s;
void solve()
{
	s.clear();
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i)
		scanf("%d", &q[i]), p[i] = -1, s.insert(i);
	p[1] = q[1];
	s.erase(q[1]);
	for (int i = 2; i <= n; ++i)
		if (q[i] > q[i - 1])
		{
			p[i] = q[i];
			s.erase(q[i]);
		}
	for (int i = 1; i <= n; ++i)
		if (p[i] == -1)
		{
			auto t = s.lower_bound(q[i]);
			if (t == s.begin())
			{
				printf("-1\n");
				return;
			}
			--t;
			p[i] = *t;
			s.erase(p[i]);
		}
	for (int i = 1; i <= n; ++i)
		printf("%d%c", p[i], i == n ? '\n' : ' ');
}
int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
		solve();
	return 0;
}