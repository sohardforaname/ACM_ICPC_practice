#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5 + 5;
char s[N];
int diff[N];
void solve()
{
	int n, x;
	scanf("%d%d", &n, &x);
	memset(diff, 0, sizeof(diff[0]) * (n + 1));
	scanf("%s", s + 1);
	for (int i = 1; i <= n; ++i)
	{
		if (s[i] == '0')
			diff[i] = diff[i - 1] + 1;
		else
			diff[i] = diff[i - 1] - 1;
	}
	int ans = 0;
	if (x == 0)
		++ans;
	for (int i = 1; i <= n; ++i)
	{
		if (diff[n] == 0 && diff[i] == x)
			++ans;
		else if (diff[n] && (x - diff[i]) % diff[n] == 0 && (x - diff[i]) / diff[n] >= 0)
			++ans;
	}
	if (diff[n] == 0 && ans)
		printf("-1\n");
	else
		printf("%d\n", ans);
}
int main()
{
	int t;
	scanf("%d", &t);
	while (t--)
		solve();
	return 0;
}