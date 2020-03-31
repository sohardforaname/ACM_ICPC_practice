#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 3e5 + 5, M = 26;
struct PAM
{
	int nxt[N][M], fail[N], cnt[N];
	int s[N], len[N], num[N];
	int n, last, p;
	int newnode(int l)
	{
		++p;
		memset(nxt[p], 0, sizeof(nxt[p]));
		cnt[p] = num[p] = 0;
		len[p] = l;
		return p;
	}
	void init()
	{
		p = -1;
		newnode(0);
		newnode(-1);
		fail[0] = 1;
		s[0] = -1;
		n = last = 0;
	}
	int getfail(int x)
	{
		while (s[n - len[x] - 1] != s[n])
			x = fail[x];
		return x;
	}
	void insert(char c)
	{
		c -= 'a';
		s[++n] = c;
		int cur = getfail(last);
		if (!nxt[cur][c])
		{
			int now = newnode(len[cur] + 2);
			fail[now] = nxt[getfail(fail[cur])][c];
			num[now] = num[fail[now]] + 1;
			nxt[cur][c] = now;
		}
		last = nxt[cur][c];
		++cnt[last];
	}
	ll count()
	{
		ll ans = 0;
		for (int i = p; i >= 0; --i)
			cnt[fail[i]] += cnt[i];
		for (int i = 2; i <= p; ++i)
			ans = max(ans, ll(len[i]) * cnt[i]);
		return ans;
	}
};
PAM pam;
char s[N];
int main()
{
	scanf("%s", s + 1);
	int len = strlen(s + 1);
	pam.init();
	for (int i = 1; i <= len; ++i)
		pam.insert(s[i]);
	printf("%lld\n", pam.count());
	return 0;
}