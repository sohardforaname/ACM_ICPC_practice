#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN = 1e6 + 5;
ll a[MAXN], sum[MAXN];
int main()
{
	int n;
	scanf("%d", &n);
	ll sum_n = 0;
	for (int i = 1; i <= n; ++i)
		scanf("%lld", &a[i]), sum_n += a[i];
	sum_n /= n;
	for (int i = 1; i <= n; ++i)
		sum[i] = sum[i - 1] + a[i] - sum_n;
	sort(sum + 1, sum + n + 1);
	ll p = 0;
	for (int i = 1; i <= n; ++i)
		p += abs(sum[i] - sum[n / 2 + 1]);
	printf("%lld", p);
	return 0;
}