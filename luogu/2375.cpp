#include "../base.h"

const int N = 1e6 + 5;
bool multi = 1;

char s[N];
int nxt[N];
ll cnt[N];
void getnext(char *s, int len)
{
	int j, k = 0;
	j = nxt[0] = -1;
	cnt[0] = 0;
	cnt[1] = 1;
	while (k < len)
	{
		if (j == -1 || s[j] == s[k])
		{
			nxt[++k] = ++j;
			cnt[k] = cnt[j] + 1; // 树形下推
		}
		else
			j = nxt[j];
	}
}

void solve()
{
	io(s);
	int len = strlen(s);
	getnext(s, len);
	int j = 0;
	ll ans = 1;
	for (int i = 1; i < len; ++i)
	{
		while (j && s[j] != s[i])
			j = nxt[j];
		if (s[i] == s[j])
			++j;
		while ((j << 1) > i + 1) // 这段代码减少了j从i按i = nxt[i]递归到i/2的过程
			j = nxt[j];
		ans = ans * (cnt[j] + 1) % mod17;
	}
	io(ans, '\n');
}

MAIN_FUNC