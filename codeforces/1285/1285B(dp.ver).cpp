#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int a[N];
long long inf = (~0ull) >> 2;
void solve()
{
	int n;
	long long sum = 0;
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i)
		scanf("%d", &a[i]), sum += a[i];
	long long ans = *max_element(a + 1, a + n + 1), cnt = 0;
	for (int i = 1; i < n; ++i)
	{
		if (cnt >= 0)
			cnt += a[i];
		else
			cnt = a[i];
		ans = max(ans, cnt);
	}
	ans = max(ans, cnt), cnt = 0;
	for (int i = 2; i <= n; ++i)
	{
		if (cnt >= 0)
			cnt += a[i];
		else
			cnt = a[i];
		ans = max(ans, cnt);
	}
	ans = max(ans, cnt), cnt = 0;
	printf("%s\n", (ans < sum ? "YES" : "NO"));
}
int main()
{
	int T;
	scanf("%d", &T);
	for (int i = 0; i < T; ++i)
		solve();
	return 0;
}