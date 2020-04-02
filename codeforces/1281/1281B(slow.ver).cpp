#include <bits/stdc++.h>
using namespace std;
const int MAXN = 5e3 + 5;
char s[MAXN], c[MAXN];
void solve()
{
	scanf("%s%s", s, c);
	if (strcmp(s, c) < 0)
	{
		printf("%s\n", s);
		return;
	}
	int lens = strlen(s);
	int minn, pos;
	for (int i = 0; i < lens; ++i)
	{
		minn = s[i], pos = i;
		for (int j = i + 1; j < lens; ++j)
			if (s[j] <= minn && s[j] < s[i])
				pos = j, minn = s[j];
		if (pos != i)
		{
			swap(s[i], s[pos]);
			break;
		}
	}
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