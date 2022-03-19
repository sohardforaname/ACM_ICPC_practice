#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e6 + 5;
int nxt[MAXN];
char str[MAXN];
void getnxt(char *t, int len)
{
	int now = 0;
	nxt[0] = len;
	while (now + 1 < len && t[now] == t[now + 1])
		++now;
	nxt[1] = now;
	int mx = 1;
	for (int i = 2; i < len; ++i)
	{
		if (i + nxt[i - mx] < mx + nxt[mx])
			nxt[i] = nxt[i - mx];
		else
		{
			int now = nxt[mx] + mx - i;
			now = max(now, 0);
			while (now + i < len && t[now] == t[now + i])
				++now;
			nxt[i] = now;
			mx = i;
		}
	}
}
int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		scanf("%s", str);
		int len = strlen(str);
		getnxt(str, len);
		long long ans = 0;
		for (int i = 1; i < len; ++i)
			ans += nxt[i] + i == len ? nxt[i] : nxt[i] + 1;
		printf("%lld\n", ans);
	}
	return 0;
}