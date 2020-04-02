#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
int mx[N], mi[N];
char s[N];
void solve()
{
	int n;
	scanf("%d%s", &n, s + 1);
	for (int i = 1; i <= n; ++i)
		mx[i] = i, mi[i] = n - i + 1;
	for (int i = 1; i < n;)
	{
		char ch = s[i];
		int k = i + 1;
		while (k < n && s[k] == s[i])
			++k;
		if (ch == '<')
			reverse(mi + i, mi + k + 1);
		else
			reverse(mx + i, mx + k + 1);
		i = k;
	}
	for (int i = 1; i <= n; ++i)
		printf("%d%c", mi[i], " \n"[i == n]);
	for (int i = 1; i <= n; ++i)
		printf("%d%c", mx[i], " \n"[i == n]);
}
int main()
{
	int t;
	scanf("%d", &t);
	while (t--)
		solve();
	return 0;
}