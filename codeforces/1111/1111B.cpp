#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN = 1e5 + 5;
int a[MAXN];
ll sum[MAXN];
int main()
{
	int n, k, m;
	scanf("%d%d%d", &n, &k, &m);
	for (int i = 1; i <= n; ++i)
		scanf("%d", &a[i]);
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; ++i)
		sum[i] = sum[i - 1] + a[i];
	long double ans = 0;
	for (int i = 0; i <= min(m, n - 1); ++i)
	{
		ll tmp = sum[n] - sum[i] + min(ll(m - i), ll(k) * (n - i));
		ans = max(ans, (long double)(tmp) / (n - i));
	}
	printf("%.15Lf\n", ans);
	return 0;
}