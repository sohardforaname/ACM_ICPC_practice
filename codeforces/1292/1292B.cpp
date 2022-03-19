#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e2 + 5;
ll x[N], y[N];
int main()
{
	ll ax, ay, bx, by;
	scanf("%lld%lld%lld%lld%lld%lld", &x[0], &y[0], &ax, &ay, &bx, &by);
	int cnt;
	for (cnt = 1; x[cnt - 1] < 5e16 && y[cnt - 1] < 5e16; ++cnt)
	{
		x[cnt] = x[cnt - 1] * ax + bx;
		y[cnt] = y[cnt - 1] * ay + by;
	}
	ll xs, ys, t;
	scanf("%lld%lld%lld", &xs, &ys, &t);
	int ans = 0;
	for (int i = 0; i < cnt; ++i)
		for (int j = 0; j < cnt; ++j)
			if (abs(xs - x[i]) + abs(ys - y[i]) + abs(x[i] - x[j]) + abs(y[i] - y[j]) <= t)
				ans = max(ans, abs(i - j) + 1);
	printf("%d\n", ans);
	return 0;
}