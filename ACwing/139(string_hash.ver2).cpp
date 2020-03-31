#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
const int MAXN = 1e6 + 5;
const int base = 13331;
ull p[MAXN << 1], prf[MAXN << 1], suf[MAXN << 1];
char s[MAXN], t[MAXN << 1];
int main()
{
	int c = 0;
	p[0] = 1;
	for (int i = 1; i < MAXN << 1; ++i)
		p[i] = p[i - 1] * base;
	while (scanf("%s", s) && s[0] != 'E')
	{
		int len = strlen(s), tlen = 0;
		t[++tlen] = '#';
		for (int i = 0; i < len; ++i)
			t[++tlen] = s[i], t[++tlen] = '#';
		prf[0] = suf[tlen + 1] = 0;
		for (int i = 1; i <= tlen; ++i)
			prf[i] = prf[i - 1] * base + t[i];
		for (int i = tlen; i >= 1; --i)
			suf[i] = suf[i + 1] * base + t[i];
		int ans = 0, l;
		for (int i = 1; i <= tlen; ++i)
		{
			l = ans;
			if (i + l > tlen&& i - l < 1)
				break;
			if (prf[i + l] - prf[i - 1] * p[l + 1] != suf[i - l] - suf[i + 1] * p[l + 1])//
				continue;
			while (i + l + 1 <= tlen && i - l - 1 >= 1 && t[i + l + 1] == t[i - l - 1])
				++l;
			ans = max(ans, l);
		}
		printf("Case %d: %d\n", ++c, ans);
	}
	return 0;
}