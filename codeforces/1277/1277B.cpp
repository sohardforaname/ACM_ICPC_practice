#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2e5 + 5;
int a[MAXN];
unordered_map<int, int>mp;
int main()
{
	int t;
	scanf("%d", &t);
	while (t--)
	{
		mp.clear();
		int n;
		scanf("%d", &n);
		for (int i = 1; i <= n; ++i)
			scanf("%d", &a[i]);
		for (int i = 1; i <= n; ++i)
		{
			while (a[i] % 2 == 0)
			{
				++mp[a[i]];
				a[i] /= 2;
			}
		}
		printf("%d\n", mp.size());
	}
	return 0;
}
