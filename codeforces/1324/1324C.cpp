#include <bits/stdc++.h>
using namespace std;
const int N = 2e5+ 5;
typedef long long ll; 
char s[N];
int minp[N];
void solve()
{
	memset(minp, 0, sizeof(minp));
	scanf("%s", s + 1);
	int n = strlen(s + 1);
	int prev = 0, maxn = 0;
	for (int i = 1; i <= n; ++i)
		if (s[i] == 'R')
			maxn = max(maxn, i - prev), prev = i;
	maxn = max(maxn, n + 1 - prev);
	printf("%d\n", maxn);
}
int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
		solve();
	return 0;
}