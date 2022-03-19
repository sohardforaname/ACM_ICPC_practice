#include <bits/stdc++.h>
using namespace std;
const int N = 3.5e3 + 5;
int a[N], b[N];
void solve()
{
	deque<int> q;
	int n, m, k;
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 1; i <= n; ++i)
		scanf("%d", &a[i]);
	for (int i = 1; i <= n; ++i)
		b[i] = max(a[i], a[n - m + i]);
	k = min(k, m - 1);
	for (int i = 1; i <= m - k; ++i)
	{
		while (q.size() && b[q.back()] > b[i])
			q.pop_back();
		q.push_back(i);
	}
	int ans = b[q.front()];
	for (int i = m - k + 1; i <= m; ++i)
	{
		while (q.size() && b[q.back()] > b[i])
			q.pop_back();
		while (q.size() && q.front() <= i - m + k)
			q.pop_front();
		q.push_back(i);
		ans = max(ans, b[q.front()]);
	}
	printf("%d\n", ans);
}
int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
		solve();
	return 0;
}