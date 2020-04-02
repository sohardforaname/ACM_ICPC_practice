#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 5;
int a[MAXN], b[MAXN], c[MAXN];
int main()
{
	int t;
	scanf("%d", &t);
lab:;
	while (t--)
	{
		int n;
		scanf("%d", &n);
		for (int i = 1; i <= n; ++i)
			scanf("%d", &a[i]);
		for (int i = 1; i <= n; ++i)
			scanf("%d", &b[i]);
		for (int i = 1; i <= n; ++i)
			c[i] = b[i] - a[i];
		for (int i = 1; i <= n; ++i)
			if (c[i] < 0)
			{
				printf("NO\n");
				goto lab;
			}
		int cnt = 0;
		for (int i = 1; i <= n;)
		{
			if (c[i])
			{
				int tmp = i;
				while (tmp <= n && c[i] == c[tmp])
					++tmp;

				i = tmp;
				++cnt;
			}
			else
				++i;
		}
		if (cnt > 1)
			printf("NO\n");
		else
			printf("YES\n");
	}
	return 0;
}