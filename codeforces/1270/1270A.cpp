#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int num[4], q[4];
vector<int>ans;
void solve()
{
	int n, k1, k2;
	scanf("%d%d%d", &n, &k1, &k2);
	int maxn1 = 0, maxn2 = 0;
	for (int i = 1; i <= k1; ++i)
	{
		scanf("%d", &n);
		maxn1 = max(maxn1, n);
	}
	for (int i = 1; i <= k2; ++i)
	{
		scanf("%d", &n);
		maxn2 = max(maxn2, n);
	}
	if (maxn1 > maxn2)
		printf("YES\n");
	else
		printf("NO\n");
	return;
}
int main()
{
	int t;
	scanf("%d", &t);
	while (t--)
		solve();
	return 0;
}