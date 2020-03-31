#include <bits/stdc++.h>
using namespace std;
const int MAXN = 6e1 + 5;
char s[MAXN][MAXN];
void solve()
{
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; ++i)
		scanf("%s", s[i] + 1);
	int f = 0;
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j)
			if (s[i][j] == 'A')
				++f;
	int minn = 5;
	if (!f)
	{
		printf("MORTAL\n");
		return;
	}
	else if (f == n * m)
		minn = 0;
	for (int i = 1; i <= n; ++i)//横行
	{
		int tag = 1;
		for (int j = 1; j <= m; ++j)
			if (s[i][j] == 'P')
			{
				tag = 0;
				break;
			}
		if (tag)
		{
			if (i == 1 || i == n)
				minn = min(1, minn);
			else
				minn = min(2, minn);
		}
	}
	for (int i = 1; i <= m; ++i)//纵行
	{
		int tag = 1;
		for (int j = 1; j <= n; ++j)
			if (s[j][i] == 'P')
			{
				tag = 0;
				break;
			}
		if (tag)
		{
			if (i == 1 || i == m)
				minn = min(1, minn);
			else
				minn = min(2, minn);
		}
	}
	if (s[1][1] == 'A' || s[1][m] == 'A' || s[n][1] == 'A' || s[n][m] == 'A')
		minn = min(2, minn);
	for (int i = 1; i <= n; ++i)
		if (s[i][1] == 'A' || s[i][m] == 'A')
			minn = min(3, minn);
	for (int i = 1; i <= m; ++i)
		if (s[1][i] == 'A' || s[n][i] == 'A')
			minn = min(3, minn);
	minn = min(4, minn);
	printf("%d\n", minn);
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