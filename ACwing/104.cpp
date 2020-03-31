#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 5;
int a[MAXN];
int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
	scanf("%d", &a[i]);
	long long ans = 0;
	sort(a, a + n);
	int p = a[n / 2];
	for (int i = 0; i < n; ++i)
		ans += abs(p - a[i]);
	printf("%lld\n", ans);
	return 0;
}
