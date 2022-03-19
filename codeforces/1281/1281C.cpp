#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e6 + 5;
char s[MAXN];
typedef long long ll;
const int mod = 1e9 + 7;
void solve()
{
	int l;
	scanf("%d", &l);
	scanf("%s", s + 1);
	int slen = strlen(s + 1);
	int cnt = 0;
	ll ans = slen;
	while (cnt < l)
	{
		++cnt;//右移
		int ti = s[cnt] - '0';//复制次数
		ll tlen = ((ans % mod - cnt % mod) % mod + mod) % mod;//复制长度
		if (slen <= l)
			for (int j = 1; j < ti && slen <= l; ++j)
				for (int i = cnt + 1; i <= cnt + tlen && slen <= l; ++i)
				{
					s[++slen] = s[i];
					if (slen > l)
						break;
				}
		ans = (ans % mod + (tlen * (ti - 1)) % mod) % mod;
	}
	printf("%lld\n", ans);
}
int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
		solve();
	return 0;
}