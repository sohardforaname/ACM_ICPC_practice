#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 5;
char s[MAXN];
void solve()
{
	scanf("%s", s + 1);
	int len = strlen(s + 1);
	for (int i = 1; i <= len; ++i)
	{
		if (s[i] == s[i - 1] && s[i] != '?')
		{
			printf("-1\n");
			return;
		}
		if (s[i] == '?')
		{
			if (s[i - 1] != 'a' && s[i + 1] != 'a')
				s[i] = 'a';
			else if (s[i - 1] != 'b' && s[i + 1] != 'b')
				s[i] = 'b';
			else if (s[i - 1] != 'c' && s[i + 1] != 'c')
				s[i] = 'c';
		}
	}
	printf("%s\n", s + 1);
	return;
}
int main()
{
	int t;
	scanf("%d", &t);
	while (t--)
		solve();
	return 0;
}