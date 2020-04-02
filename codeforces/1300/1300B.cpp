#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int a[N << 1];
void solve()
{
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n * 2; ++i)
		scanf("%d", &a[i]);
	sort(a + 1, a + n * 2 + 1);
	printf("%d\n", abs(a[n] - a[n + 1]));
}
int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
		solve();
	return 0;
}