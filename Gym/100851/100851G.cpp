#include <bits/stdc++.h>
using namespace std;
const int N = 1e4 + 5;
typedef long long ll;
vector<pair<int, int> >v;
pair<int, int>p[N], dif[N];
bool vis[1005];
int main()
{
#ifndef _Aya
	//freopen("generators.in", "r", stdin);
	//freopen("generators.out", "w", stdout);
#endif
	int n, k, a, b, c, x;
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= n; ++i)
	{
		memset(vis, 0, sizeof(vis));
		v.clear();
		scanf("%d%d%d%d", &x, &a, &b, &c);
		v.push_back(make_pair(x, 0));
		vis[x] = 1;
		for (int j = 1; j < c; ++j)
		{
			x = (a * x + b) % c;
			if (!vis[x])
				v.push_back(make_pair(x, j)), vis[x] = 1;
			else
				break;
		}
		dif[i] = make_pair(-1, -1);
		sort(v.begin(), v.end(), greater<pair<int, int> >());
		p[i] = v[0];
		for (int j = 1; j < v.size(); ++j)
			if ((v[0].first - v[j].first) % k != 0 && v[j].first > dif[i].first)
				dif[i] = v[j];
		assert(p[i].first > dif[i].first);
	}
	ll sum = 0;
	for (int i = 1; i <= n; ++i)
		sum += p[i].first;
	if (sum % k)
	{
		printf("%lld\n", sum);
		for (int i = 1; i <= n; ++i)
			printf("%d%c", p[i].second, " \n"[i == n]);
	}
	else
	{
		int minn = 1e4, minpos = 0;
		for (int i = 1; i <= n; ++i)
			if (dif[i].second != -1 && p[i].first - dif[i].first < minn)
				minn = p[i].first - dif[i].first, minpos = i;
		if (!minpos)
			printf("-1\n");
		else
		{
			p[minpos] = dif[minpos];
			sum -= minn;
			printf("%lld\n", sum);
			for (int i = 1; i <= n; ++i)
				printf("%d%c", p[i].second, " \n"[i == n]);
		}
	}
	return 0;
}