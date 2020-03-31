#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5 + 5;
int a[N];
void solve()
{
	int n, m;
	ll ans = 1;
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; ++i)
		scanf("%d", &a[i]);
	if (n > 1000)
	{
		printf("0\n");
		return;
	}
	for (int i = 1; i <= n; ++i)
		for (int j = i + 1; j <= n; ++j)
			ans = ans * abs(a[i] - a[j]) % m;
	printf("%lld\n", ans);
}
int main()
{
	int t = 1;
	//scanf("%d", &t);
	while (t--)
		solve();
	return 0;
}