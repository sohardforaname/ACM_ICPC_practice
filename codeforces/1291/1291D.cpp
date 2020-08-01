#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
char s[N];
int cnt[N][26];
int main()
{
	scanf("%s", s + 1);
	int len = strlen(s + 1);
	for (int i = 1; i <= len; ++i)
	{
		memcpy(cnt[i], cnt[i - 1], sizeof(cnt[i - 1]));
		++cnt[i][s[i] - 'a'];
	}
	int m;
	scanf("%d", &m);
	for (int i = 1; i <= m; ++i)
	{
		int l, r;
		scanf("%d%d", &l, &r);
		if (l == r)
			printf("Yes\n");
		else if (s[l] != s[r])
			printf("Yes\n");
		else
		{
			int zero = 0;
			for (int i = 0; i < 26; ++i)
				zero += !(cnt[r][i] - cnt[l - 1][i]);
			if (zero >= 24)
				printf("No\n");
			else
				printf("Yes\n");
		}
	}
	return 0;
}