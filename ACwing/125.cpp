#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN = 5e5 + 5;
struct Cow
{
	ll w, s;
};
Cow c[MAXN];
ll sum[MAXN];
int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i)
		scanf("%lld%lld", &c[i].w, &c[i].s);
	sort(c + 1, c + n + 1, [](Cow& a, Cow& b)->bool {return a.s + a.w < b.s + b.w; });
	for (int i = 1; i <= n; ++i)
		sum[i] = sum[i - 1] + c[i].w;
	ll ans = -0x3f3f3f3f3f3f3f3f;
	for (int i = 1; i <= n; ++i)
		ans = max(ans, sum[i - 1] - c[i].s);
	printf("%lld\n", ans);
	return 0;
}