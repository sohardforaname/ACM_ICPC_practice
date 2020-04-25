#include <bits/stdc++.h>
using namespace std;
const int N = 1e2 + 5;
int a[N];
void solve()
{
	int n;
	scanf("%d", &n);
	int sum = 0, ans = 0;
	for (int i = 1; i <= n; ++i)
	{
		scanf("%d", &a[i]), sum += a[i];
		if (a[i] == 0)
			++sum, ++a[i], ++ans;
	}
	if (sum == 0)
	{
		bool f = 0;
		for (int i = 1; i <= n; ++i)
			if (~i)
			{
				f = 1;
				break;
			}
		++ans;
		if (!f)
			++ans;
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