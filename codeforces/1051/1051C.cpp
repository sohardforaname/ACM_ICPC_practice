#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e2 + 5;
int a[MAXN];
int buc[MAXN];
int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i)
	{
		scanf("%d", &a[i]);
		++buc[a[i]];
	}
	int k = 0, k1 = 0;
	for (int i = 1; i < MAXN; ++i)
	{
		if (buc[i] == 1)
			++k;
		if (buc[i] >= 3)
			++k1;
	}
	if (k % 2 && !k1)
		printf("NO\n");
	else
	{
		printf("YES\n");
		if (k % 2)
		{
			k /= 2;
			bool f = 1;
			for (int i = 1; i <= n; ++i)
			{
				if (k && buc[a[i]] == 1)
					printf("B"), --k;
				else if (f && buc[a[i]] >= 3)
					printf("B"), f = 0;
				else
					printf("A");
			}
		}
		else
		{
			k /= 2;
			for (int i = 1; i <= n; ++i)
			{
				if (k && buc[a[i]] == 1)
					printf("B"), --k;
				else
					printf("A");
			}
		}
		printf("\n");
	}
	return 0;
}