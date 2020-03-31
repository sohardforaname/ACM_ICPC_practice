#include <bits/stdc++.h>
using namespace std;
const int MAXN = 5e5 + 5;
const int MAXM = 26;
struct PAM
{
	int nxt[MAXN][MAXM], fail[MAXN], cnt[MAXN];
	int num[MAXN], len[MAXN], s[MAXN];
	int last, n, p;
	int newnode(int l)
	{
		++p;
		for (int i = 0; i < MAXM; ++i)
			nxt[p][i] = 0;
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
	void count()
	{
		for (int i = p; i >= 0; --i)
			cnt[fail[i]] += cnt[i];
	}
};
char str[MAXN];
PAM pam;
int main()
{
	scanf("%s", str + 1);
	int n = strlen(str + 1);
	pam.init();
	int k = 0;
	for (int i = 1; i <= n; ++i)
	{
		str[i] = (str[i] - 97 + k) % 26 + 97;
		pam.insert(str[i]);
		printf("%d%c", pam.num[pam.last], i == n ? '\n' : ' ');
		k = pam.num[pam.last];
	}
	return 0;
}