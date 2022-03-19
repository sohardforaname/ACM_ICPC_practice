#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN = 1e6 + 5;
const int MAXM = 26;
const int mod = 19930726;
struct node
{
	int len;
	int cnt;
	node(int _len, int _cnt) :len(_len), cnt(_cnt) {}
	node() {}
	bool operator<(const node& a)const
	{
		return len == a.len ? cnt > a.cnt : len > a.len;
	}
};
node t[MAXN];
ll inv(ll a, ll b, ll p)
{
	ll res = 1;
	while (b)
	{
		if (b & 1)
			res = (res * a) % p;
		a = (a * a) % p;
		b >>= 1;
	}
	return res;
}
struct PAM
{
	int nxt[MAXN][MAXM], fail[MAXN], cnt[MAXN];
	int num[MAXN], len[MAXN], s[MAXN];
	int last, n, p;
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
			num[now] = num[fail[now]];
			nxt[cur][c] = now;
		}
		last = nxt[cur][c];
		++cnt[last];
	}
	ll count(ll k)
	{
		ll ans = 1;
		for (int i = p; i >= 2; --i)
			cnt[fail[i]] = (cnt[fail[i]] + cnt[i]) % mod;
		for (int i = 2; i <= p; ++i)
			t[i] = node(len[i], cnt[i]);
		sort(t + 2, t + p + 1);
		int i = 2;
		while (k)
		{
			if (i == p + 1)
				return -1;
			if (t[i].len % 2 == 0)
			{
				++i;
				continue;
			}
			if (t[i].cnt <= k)
			{
				ans = ans * inv(t[i].len, t[i].cnt, mod) % mod;
				k -= t[i].cnt;
			}
			else if(t[i].cnt)
			{
				ans = ans * inv(t[i].len, k, mod) % mod;
				k = 0;
			}
			++i;
		}
		return ans;
	}
};
PAM p;
char str[MAXN];
int main()
{
	int n;
	ll k;
	scanf("%d%lld", &n, &k);
	p.init();
	scanf("%s", str + 1);
	for (int i = 1; i <= n; ++i)
		p.insert(str[i]);
	printf("%lld\n", p.count(k));
	return 0;
}