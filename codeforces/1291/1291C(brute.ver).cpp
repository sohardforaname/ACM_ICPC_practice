#include <bits/stdc++.h>
using namespace std;
const int N = 3.5e3 + 5;
int a[N];
void solve()
{
	int n, m, k;
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 1; i <= n; ++i)
		scanf("%d", &a[i]);
	k = min(k, m - 1);
	int ans = 0;
	for (int i = 0; i <= k; ++i)
	{
		int tmp = 1e9;
		for (int j = 0; j <= m - k - 1; ++j)
			tmp = min(tmp, max(a[i + j + 1], a[n + i - m + 1 + j]));
		ans = max(ans, tmp);
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