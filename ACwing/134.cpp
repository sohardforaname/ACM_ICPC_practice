#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2e5 + 5;
typedef pair<int, int> pii;
pii a[MAXN];
bool cmp(pii& a, pii& b)
{
	return a.first == b.first ? a.second < b.second : a.first < b.first;
}
int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i)
		scanf("%d", &a[i].first), a[i].second = i;
	sort(a + 1, a + n + 1, cmp);
	int ans = 0, pre = 0, mi, ma, dir = -1;
	for (int i = 1; i <= n;)
	{
		int j = i + 1;
		while (j <= n && a[j].first == a[i].first)
			++j;
		mi = a[i].second, ma = a[j - 1].second;
		if (dir == -1)
		{
			if (ma < pre)
				pre = mi;
			else
				dir = 1, pre = ma;
		}
		else
		{
			if (mi > pre)
				pre = ma;
			else
				dir = -1, ++ans, pre = mi;
		}
		i = j;
	}
	printf("%d\n", ans);
	return 0;
}