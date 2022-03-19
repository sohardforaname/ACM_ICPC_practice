#include <bits/stdc++.h>
using namespace std;
const int MAXN = 5e2 + 5;
char s[MAXN];
bool vis[26];
int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		memset(vis, 0, sizeof(vis));
		int n;
		scanf("%s", s + 1);
		n = strlen(s + 1);
		for (int i = 1; i <= n;)
		{
			int j = i;
			while (j <= n && s[j] == s[i])
				++j;
			if ((j - i) % 2)
				vis[s[i] - 'a'] = 1;
			i = j;
		}
		for (int i = 0; i < 26; ++i)
			if (vis[i])
				printf("%c", char(i + 'a'));
		printf("\n");
	}
	return 0;
}