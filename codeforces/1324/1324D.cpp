#include <bits/stdc++.h>
using namespace std;
const int N = 2e5+ 5;
typedef long long ll; 
int a[N], b[N];
int add[N], sub[N];
void solve()
{
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i)
		scanf("%d", &a[i]);
	for (int i = 1; i <= n; ++i)
		scanf("%d", &b[i]);
	for (int i = 1; i <= n; ++i)
		add[i] = a[i] - b[i];
	sort(add + 1, add + n + 1);
	ll cnt = 0;
	for (int i = 1; i <= n; ++i)
		cnt += n - (upper_bound(add + 1 + i, add + n + 1, -add[i]) - add - 1);
	printf("%lld\n", cnt);
}
int main()
{
	int T = 1;
	//scanf("%d", &T);
	while (T--)
		solve();
	return 0;
}
/*
ai+aj>bi+bj
ai-bi>-(aj-bj)
def. ci=ai-bi
ci>-cj;(j>i)
*/