#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
int a[N];
void solve()
{
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i)
		scanf("%d", &a[i]);
	int l = 0, r = 0;
	for (int i = 1; i <= n; ++i)
		if (a[i] == 1)
		{
			l = i, r = i;
			break;
		}
	int maxn = 1;
	printf("1");
	for (int i = 2; i <= n; ++i)
	{
		if (l == 1)
			++r, maxn = max(maxn, a[r]);
		else if (r == n)
			--l, maxn = max(maxn, a[l]);
		else
		{
			if (a[l - 1] > a[r + 1])
				++r, maxn = max(maxn, a[r]);
			else
				--l, maxn = max(maxn, a[l]);
		}
		if (r - l + 1 == maxn)
			printf("1");
		else
			printf("0");
	}
	printf("\n");
}
int main()
{
	int t;
	scanf("%d", &t);
	while (t--)
		solve();
	return 0;
}