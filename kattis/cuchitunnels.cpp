#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 5;
int d[N];
int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i)
		scanf("%d", &d[i]);
	for (int i = 2; i <= n; ++i)
		--d[i];
	int cur = 1;
	for (int i = 1; i <= n; ++i)
	{
		if (i > cur)
		{
			printf("NO\n");
			return 0;
		}
		else
			cur += d[i];
	}
	printf("%s\n", cur == n ? "YES" : "NO");
	return 0;
}