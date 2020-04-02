#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN = 2e5 + 5;
map<int, int>mp[MAXN];
int a[MAXN], tmp[MAXN];
int main()
{
	int n;
	scanf("%d", &n);
	ll sum = 0;
	for (int i = 1; i <= n; ++i)
		scanf("%d", &a[i]), sum += a[i];
	int m;
	int s, t, u;
	scanf("%d", &m);
	for (int i = 1; i <= m; ++i)
	{
		scanf("%d%d%d", &s, &t, &u);
		int pos = mp[s][t];
		if (pos)//发现了之前的，需要删掉
		{
			if (tmp[pos] <= a[pos])
				++sum;
			--tmp[pos];
		}
		mp[s][t] = u;
		if (tmp[u] < a[u])
			--sum;
		++tmp[u];
		printf("%lld\n", sum);
	}
	return 0;
}