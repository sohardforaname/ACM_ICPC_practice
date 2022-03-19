#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5 + 5;
char s[N], t[N];
int b[26];
int nxt[N][26];
void solve()
{
	scanf("%s%s", s, t);
	memset(b, 0, sizeof(b));
	int lena = strlen(s), lenb = strlen(t);
	for (int i = 0; i < lena; ++i)
		++b[s[i] - 'a'];
	for (int i = 0; i < lenb; ++i)
		if (b[t[i] - 'a'] == 0)
		{
			printf("-1\n");
			return;
		}
	memset(nxt, 0x3f, sizeof(nxt[0]) * (lena + 3));
	for (int i = lena - 1; i >= 0; --i)
	{
		for (int j = 0; j < 26; ++j)
			nxt[i][j] = nxt[i + 1][j];
		nxt[i][s[i] - 'a'] = i;
	}
	int ans = 1, spos = 0;
	for (int i = 0; i < lenb; ++i)
	{
		if (spos == lena || nxt[spos][t[i] - 'a'] == 0x3f3f3f3f)
			++ans, spos = 0;
		spos = nxt[spos][t[i] - 'a'] + 1;
	}
	printf("%d\n", ans);
}
int main()
{
	int t;
	scanf("%d", &t);
	while (t--)
		solve();
	return 0;
}