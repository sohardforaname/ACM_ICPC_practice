#include <bits/stdc++.h>
using namespace std;
const int MAXN = 5e5 + 5;
const int MAXM = 26;
struct PAM
{
	int nxt[MAXN][MAXM], fail[MAXN], len[MAXN];
	int num[MAXN], cnt[MAXN], s[MAXN];
	int trans[MAXN];
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
			if (len[now] < 2)
				trans[now] = fail[now];
			else
			{
				int tmp = trans[cur];
				while (s[n - len[tmp] - 1] != s[n] || (len[tmp] + 2) * 2 > len[now])
					tmp = fail[tmp];
				trans[now] = nxt[tmp][c];
			}
		}
		last = nxt[cur][c];
		++cnt[last];
	}
	int count()
	{
		int maxn = 0;
		for (int i = p; i >= 0; --i)
			if (len[i] % 4 == 0 && len[trans[i]] == len[i] / 2)
				maxn = max(maxn, len[i]);
		return maxn;
	}
};
PAM p;
char str[MAXN];
int main()
{
	int n;
	scanf("%d", &n);
	scanf("%s", str + 1);
	p.init();
	for (int i = 1; i <= n; ++i)
		p.insert(str[i]);
	printf("%d\n", p.count());
	return 0;
}