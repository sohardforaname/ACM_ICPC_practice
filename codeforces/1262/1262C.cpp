#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2e3 + 5;
char s[MAXN], s1[MAXN];
void solve()
{
	int n, k;
	memset(s, 0, sizeof(s));
	scanf("%d%d", &n, &k);
	k -= 1;
	for (int i = 0; i < k; ++i)
		s[i * 2] = '(', s[i * 2 + 1] = ')';
	for (int i = 2 * k; i < 2 * k + (n - 2 * k) / 2; ++i)
		s[i] = '(';
	for (int i = 2 * k + (n - 2 * k) / 2; i < n; ++i)
		s[i] = ')';
	scanf("%s", s1);
	printf("%d\n", n);
	for (int i = 0; i < n; ++i)
	{
		int pos = i;
		while (s[i] != s1[pos])
			++pos;
		printf("%d %d\n", i + 1, pos + 1);
		reverse(s1 + i, s1 + pos + 1);
	}
}
int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
		solve();
	return 0;
}