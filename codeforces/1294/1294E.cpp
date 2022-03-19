#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
vector<vector<int> >v;
int offset[N];
int main()
{
	int n, m;
	scanf("%d%d", &n, &m);
	v.resize(n);
	for (int i = 0; i < n; ++i)
	{
		v[i].resize(m);
		for (int j = 0; j < m; ++j)
			scanf("%d", &v[i][j]);
	}
	long long ans = 0;
	for (int j = 0; j < m; ++j)
	{
		memset(offset, 0, sizeof(offset[0]) * (n + 5));
		for (int i = 0; i < n; ++i)
		{
			if (v[i][j] > n * m || (v[i][j] - j - 1) % m)
				continue;
			int pos = (v[i][j] - j - 1) / m;
			++offset[(i - pos + n) % n];
		}
		int res = 0x3f3f3f3f;
		for (int i = 0; i < n; ++i)
			res = min(res, n - offset[i] + i);
		ans += res;
	}
	printf("%lld\n", ans);
	return 0;
}