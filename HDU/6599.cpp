#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int N = 3e5 + 5, M = 26;
const ull hs1 = 13331;
int ans[N];
struct Hash
{
	ull b[N], hs[N];
	char s[N];
	void init()
	{
		b[0] = 1;
		for (int i = 1; i < N; ++i)
			b[i] = b[i - 1] * hs1;
	}
	void insert()
	{
		int len = strlen(s + 1);
		for (int i = 1; i <= len; ++i)
			hs[i] = hs[i - 1] * hs1 + s[i];
	}
	ull geths(int l, int r)
	{
		return hs[r] - hs[l - 1] * b[r - l + 1];
	}
	bool check(int l, int r)
	{
		int len = r - l + 1, mid = (r + l) >> 1;
		if (len & 1)
			return geths(l, mid) == geths(mid, r);
		else
			return geths(l, mid) == geths(mid + 1, r);
	}
};
Hash h;
struct PAM
{
	int nxt[N][M], fail[N], num[N], len[N];
	int s[N], cnt[N], id[N];
	int p, last, n;
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
		n = last = 0;
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
		++cnt[last], id[last] = n;	
	}
	void count()
	{
		for (int i = p; i >= 0; --i)
			cnt[fail[i]] += cnt[i];
		for (int i = 2; i <= p; ++i)
			if (h.check(id[i] - len[i] + 1, id[i]))
				ans[len[i]] += cnt[i];
	}
};
PAM pam;
int main()
{
	h.init();
	while (~scanf("%s", h.s + 1))
	{
		h.insert();
		memset(ans, 0, sizeof(ans));
		int len = strlen(h.s + 1);
		pam.init();
		for (int i = 1; i <= len; ++i)
			pam.insert(h.s[i]);
		pam.count();
		for (int i = 1; i <= len; ++i)
			printf("%d%c", ans[i], " \n"[i == len]);
	}
	return 0;
}