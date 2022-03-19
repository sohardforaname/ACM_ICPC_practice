#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 5;
const int MAXM = 26;
struct PAM
{
	int nxt[MAXN][MAXM], fail[MAXN], cnt[MAXN];
	int num[MAXN], s[MAXN], len[MAXN];
	int n, p, last;
	int newnode(int l)
	{
		++p;
		memset(nxt[p], 0, sizeof(nxt[p]));
		cnt[p] = 0;
		num[p] = 0;
		len[p] = l;
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
	int insert(int c)
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
		return len[last];
	}
};
PAM p1, p2;
int x[MAXN], y[MAXN];
char str[MAXN];
int main()
{
	scanf("%s", str + 1);
	int n = strlen(str + 1);
	p1.init();
	p2.init();
	for (int i = 1; i <= n; ++i)
		x[i] = p1.insert(str[i]);
	for (int i = n; i; --i)
		y[i] = p2.insert(str[i]);
	int ans = 0;
	for (int i = 2; i < n; ++i)
		ans = max(ans, x[i] + y[i + 1]);
	printf("%d\n", ans);
	return 0;
}