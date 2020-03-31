#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN = 5005;
int s[MAXN][MAXN];
int main()
{
	int n, r, a, b, v;
	scanf("%d%d", &n, &r);
	for (int i = 0; i < n; ++i)
		scanf("%d%d%d", &a, &b, &v), s[a + 1][b + 1] = v;
	for (int i = 1; i < MAXN; ++i)
		for (int j = 1; j < MAXN; ++j)
			s[i][j] += s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1];
	int maxn = 0;
	for (int i = r; i < MAXN; ++i)
		for (int j = r; j < MAXN; ++j)
			maxn = max(maxn, s[i][j] + s[i - r][j - r] - s[i][j - r] - s[i - r][j]);
	printf("%lld\n", maxn);
	return 0;
}
