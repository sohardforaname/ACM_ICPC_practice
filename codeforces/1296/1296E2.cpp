#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
int c[N];
char s[N];
vector<int>v(N + 1, -int('a'));
int main()
{
	int n, ans = 0;
	scanf("%d%s", &n, s + 1);
	for (int i = 1; i <= n; ++i)
	{
		int k = s[i];
		k = -k;
		int pos = lower_bound(v.begin(), v.end(), k) - v.begin();
		v[pos] = k;
		ans = max(ans, pos);
		c[i] = pos;
	}
	printf("%d\n", ans + 1);
	for (int i = 1; i <= n; ++i)
		printf("%d%c", c[i] + 1, " \n"[i == n]);
	return 0;
}