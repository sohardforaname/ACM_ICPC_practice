#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int a[N];
const long long inf = (~0ull) >> 2;
void solve()
{
	int n;
	long long sum;
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i)
		scanf("%d", &a[i]);
	sum = 0;
	for (int i = 1; i <= n; ++i)
	{
		sum += a[i];
		if (sum <= 0)
		{
			printf("NO\n");
			return;
		}
	}
	sum = 0;
	for (int i = n; i >= 1; --i)
	{
		sum += a[i];
		if (sum <= 0)
		{
			printf("NO\n");
			return;
		}
	}
	printf("YES\n");
}
int main()
{
	int T;
	scanf("%d", &T);
	for (int i = 0; i < T; ++i)
		solve();
	return 0;
}