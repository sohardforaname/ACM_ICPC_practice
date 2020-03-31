#include <bits/stdc++.h>
using namespace std;
const int MAXN = 3e5 + 5;
const int MAXM = 26;
typedef long long ll;
struct PAM
{
	int nxt[MAXN][MAXM], fail[MAXN], len[MAXN];
	int num[MAXN], cnt[MAXN], s[MAXN];
	int n, p, last;
	int newnode(int l)
	{
		++p;
		for (int i = 0; i < MAXM; ++i)
			nxt[p][i] = 0;
		len[p] = l;
		cnt[p] = 0;
		num[p] = 0;
		return p;
	}
	void init()
	{
		p = -1;
		newnode(0);
		newnode(-1);
		n = 0;
		last = 0;
		s[0] = -1;
		fail[0] = 1;
	}
	int getfail(int x)
	{
		while (s[n - len[x] - 1] != s[n])
			x = fail[x];
		return x;
	}
	void insert(int c)
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
	ll maxm()
	{
		ll ans = 0;
		for (int i = p; i >= 0; --i)
			cnt[fail[i]] += cnt[i];
		for (int i = p; i >= 0; --i)
			ans = max(ans, ll(cnt[i]) * len[i]);
		return ans;
	}
};
PAM p;
char str[MAXN];
int main()
{
	p.init();
	scanf("%s", str + 1);
	int n = strlen(str + 1);
	for (int i = 1; i <= n; ++i)
		p.insert(str[i]);
	printf("%lld", p.maxm());
	return 0;
}
