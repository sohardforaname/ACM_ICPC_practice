#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2e5 + 5;
char str1[MAXN], str2[MAXN];
int cnt1[26], cnt2[26];
bool solve(int n)
{
	memset(cnt1, 0, sizeof(cnt1));
	memset(cnt2, 0, sizeof(cnt2));
	for (int i = 1; i <= n; ++i)
	{
		++cnt1[str1[i] - 'a'];
		++cnt2[str2[i] - 'a'];
	}
	for (int i = 0; i < 26; ++i)
		if (cnt1[i] != cnt2[i])
			return 0;
	for (int i = 0; i < 26; ++i)
		if (cnt1[i] > 1)
			return 1;
	int rev1 = 0, rev2 = 0;
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= n - i; ++j)
		{
			if (str1[j] > str1[j + 1])
				++rev1, swap(str1[j], str1[j + 1]);
			if (str2[j] > str2[j + 1])
				++rev2, swap(str2[j], str2[j + 1]);
		}
	return rev1 % 2 == rev2 % 2;
}
int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		int n;
		scanf("%d", &n);
		scanf("%s%s", str1 + 1, str2 + 1);
		printf(solve(n) ? "YES\n" : "NO\n");
	}
	return 0;
}