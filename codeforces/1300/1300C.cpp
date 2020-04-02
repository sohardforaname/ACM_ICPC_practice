#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int a[N], pre[N], suf[N];
void solve()
{
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i)
		scanf("%u", &a[i]);
	pre[0] = suf[n + 1] = INT_MAX;
	for (int i = 1; i <= n; ++i)
		pre[i] = pre[i - 1] & (~a[i]);
	for (int i = n; i; --i)
		suf[i] = suf[i + 1] & (~a[i]);
	int maxn = INT_MIN, maxpos = 1;
	for (int i = 1; i <= n; ++i)
		if ((pre[i - 1] & a[i] & suf[i + 1]) > maxn)
			maxn = pre[i - 1] & a[i] & suf[i + 1], maxpos = i;
	printf("%d ", a[maxpos]);
	for (int i = 1; i <= n; ++i)
		if (i != maxpos)
			printf("%d%c", a[i], " \n"[i == n]);
}
int main()
{
	int T = 1;
	//scanf("%d", &T);
	while (T--)
		solve();
	return 0;
}
//(a|b)-b
//1010|1100=1110-1100=0010
//1 1->0 0 1->0 1 0->1 0 0->0