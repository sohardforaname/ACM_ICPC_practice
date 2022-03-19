#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 5;
int st[N][15], len;
char s[N];
void set_st()
{
	for (int i = 1; i <= len; ++i)
		st[i][0] = s[i];
	for (int i = 1; (1 << i) <= len; ++i)
		for (int j = 1; j + (1 << i) - 1 <= len; ++j)
			st[j][i] = min(st[j][i - 1], st[j + (1 << (i - 1))][i - 1]);
}
int query(int l, int r)
{
	int k = log(r - l + 1) / log(2.0);
	return min(st[l][k], st[r - (1 << k) + 1][k]);
}
int findp(int x, int l, int r)
{
	for (int i = l; i <= r; ++i)
		if (s[i] == x)
			return i;
	return -1;
}
char ans[N];
int top;
int main()
{
	int m = 0;
	while (~scanf("%s%d", s + 1, &m))
	{
		top = 0;
		len = strlen(s + 1);
		set_st();
		int l = 1, r = m + 1;
		for (int i = 1; i <= len - m; ++i)
		{
			int x = query(l, r);
			int pos = findp(x, l, r);
			ans[++top] = x;
			l = pos + 1, r = m + 1 + i;
		}
		bool zflag = 0;
		for (int i = 1; i <= top; ++i)
		{
			if (!zflag && ans[i] - '0')
			{
				printf("%c", ans[i]);
				zflag = 1;
			}
			else if (zflag)
				printf("%c", ans[i]);
		}
		if (!zflag)
			putchar('0');
		printf("\n");
	}
	return 0;
}