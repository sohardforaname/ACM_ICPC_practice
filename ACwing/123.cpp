#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN = 1e4 + 5;
int posx[MAXN];
int posy[MAXN];
int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i)
		scanf("%d%d", &posx[i], &posy[i]);
	ll ans = 0;
	sort(posy + 1, posy + n + 1);
	int midy = posy[n / 2 + 1];
	for (int i = 1; i <= n; ++i)
		ans += abs(midy - posy[i]);
	sort(posx + 1, posx + n + 1);
	for (int i = 1; i <= n; ++i)
		posx[i] -= i;
	sort(posx + 1, posx + n + 1);
	int midx = posx[n / 2 + 1];
	for (int i = 1; i <= n; ++i)
		ans += abs(midx - posx[i]);
	printf("%lld\n", ans);
	return 0;
}