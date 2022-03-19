#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e2 + 5;
int a[MAXN];
bool vis[MAXN];
int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		memset(vis, 0, sizeof(vis));
		int n;
		scanf("%d", &n);
		for (int i = 1; i <= n; ++i)
			scanf("%d", &a[i]);
		for (int i = 1; i < n; ++i)
		{
			int minn = 105, minpos = 0;
			for (int j = 1; j < n; ++j)
				if (a[j] > a[j + 1] && vis[j] == 0)
				{
					if (minn > a[j + 1])
						minn = a[j + 1], minpos = j;
				}
			if (minpos)
			{
				swap(a[minpos], a[minpos + 1]);
				vis[minpos] = 1;
			}
		}
		for (int i = 1; i <= n; ++i)
			printf("%d%c", a[i], i == n ? '\n' : ' ');
	}
	return 0;
}