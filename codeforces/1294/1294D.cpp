#include <bits/stdc++.h>
using namespace std;
int a[400005];
int main()
{
	int q, x, d = 0, n;
	scanf("%d%d", &q, &x);
	memset(a, -1, sizeof(a));
	while (q--)
	{
		scanf("%d", &n);
		++a[n % x];
		while (a[d % x] * x + d % x >= d)
			++d;
		printf("%d\n", d);
	}
	return 0;
}