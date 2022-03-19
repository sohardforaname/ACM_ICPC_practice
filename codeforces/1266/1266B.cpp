#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	long long a;
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i)
	{
		scanf("%lld", &a);
		if (a <= 14)
		{
			printf("NO\n");
			continue;
		}
		a = a % 14;
		if (a < 1 || a > 6)
			printf("NO\n");
		else
			printf("YES\n");
	}
	return 0;
}