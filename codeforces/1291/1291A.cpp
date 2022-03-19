#include <bits/stdc++.h>
using namespace std;
const int N = 3e3 + 5;
char s[N];
void solve()
{
	int n;
	scanf("%d%s", &n, s + 1);
	int sum = 0;
	for (int i = 1; i <= n; ++i)
		sum += s[i] % 2;
	if (sum < 2)
		puts("-1");
	else
	{
		for (int i = 1, cnt = 0; i <= n && cnt < 2; ++i)
			if (s[i] % 2)
				putchar(s[i]), ++cnt;
		printf("\n");
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