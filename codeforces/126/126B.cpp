#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e6 + 5;
int fail[MAXN];
bool vis[MAXN];
char s[MAXN];
void getfail(char *s, int len)
{
	int j = -1, k = 0;
	fail[0] = -1;
	while (k < len)
	{
		if (j == -1 || s[j] == s[k])
			fail[++k] = ++j;
		else
			j = fail[j];
	}
}
int main()
{
	scanf("%s", s);
	int len = strlen(s);
	getfail(s, len);
	int ans = 0;
	int tmp = fail[len];
	while (tmp)
	{
		vis[tmp] = 1;
		tmp = fail[tmp];
	}
	for (int i = 0; i < len; ++i)
		if (fail[i] <= fail[len] && vis[fail[i]])
			ans = max(ans, fail[i]);
	if (!ans)
		printf("Just a legend\n");
	else
	{
		for (int i = 0; i < ans; ++i)
			printf("%c", s[i]);
		printf("\n");
	}
	return 0;
}