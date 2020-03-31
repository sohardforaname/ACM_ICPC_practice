#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e3 + 5;
int a[MAXN];
int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		int n;
		scanf("%d", &n);
		for (int i = 1; i <= n; ++i)
			scanf("%d", &a[i]);
		sort(a + 1, a + n + 1, greater<int>());
		for (int i = 1; i <= n; ++i)
		{
			if (a[i] < i)
			{
				printf("%d\n", i - 1);
				break;
			}
			else if (i == n)
			{
				printf("%d\n", i);
				break;
			}
		}
	}
	return 0;
}