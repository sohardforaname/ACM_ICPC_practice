#include <bits/stdc++.h>
using namespace std;
const int MAXN = 5e3 + 5;
char s[MAXN], c[MAXN];
void solve()
{
	scanf("%s%s", s, c);
	int slen = strlen(s);
	int sx = slen - 1, sy = slen - 1, x = slen;
	for (int i = slen - 1; i >= 0; --i)
	{
		if (x != slen && s[i] > s[x])
			sx = x, sy = i;
		else if (x == slen || s[i] < s[x])
			x = i;
	}
	swap(s[sx], s[sy]);
	if (strcmp(s, c) < 0)
		printf("%s\n", s);
	else
		printf("---\n");
	return;
}
int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
		solve();
	return 0;
}