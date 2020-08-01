#include <bits/stdc++.h>
using namespace std;
const int N = 3e5 + 5;
int a[N];
void solve()
{
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i)
		scanf("%d", &a[i]);
	int l = 1, r = n;
	for (; l <= n && a[l] >= l - 1; ++l)
		;
	for (; r && a[r] >= n - r; --r)
		;
	--l, ++r;
	if (l >= r)
		printf("Yes\n");
	else
		printf("No\n");
}
int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
		solve();
	return 0;
}