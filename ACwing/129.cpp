#include <bits/stdc++.h>
using namespace std;
int a[25];
int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i)
		a[i] = i;
	int k = 0;
	int maxn;
	bool f;
	do
	{
		f = 0;
		maxn = 0;
		for (int i = 1; i <= n; ++i)
		{
			if (a[i] > maxn)
				maxn = a[i];
			else if (a[i] < maxn)
			{
				for (int j = i + 1; j <= n; ++j)
					if (a[j] < maxn && a[i] < a[j])
					{
						f = 1;
						goto lab;
					}
			}
		}
	lab:;
		if (!f)
		{
			++k;
			for (int i = 1; i <= n; ++i)
				printf("%d", a[i]);
			printf("\n");
		}
	} while (next_permutation(a + 1, a + n + 1) && k < 20);
	return 0;
}