#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
typedef long long ll;
vector<pair<int, string> >v, ans;
#define pb push_back
#define mp make_pair
#define len(x) (x.first*x.second.size())
void init(int n, int m)
{
	v.clear();
	ans.clear();
	for (int i = 1; i <= n; ++i)
	{
		if (i < n)
		{
			v.push_back(mp(m - 1, "R"));
			v.push_back(mp(m - 1, "L"));
			v.push_back(mp(1, "D"));
		}
		else
			v.push_back(mp(m - 1, "R"));
	}
	for (int i = 1; i <= m; ++i)
	{
		if (i < m)
		{
			v.push_back(mp(n - 1, "U"));
			v.push_back(mp(n - 1, "D"));
			v.push_back(mp(1, "L"));
		}
		else
			v.push_back(mp(n - 1, "U"));
	}
}
int solve()
{
	int n, m, k;
	scanf("%d%d%d", &n, &m, &k);
	if (k > 4 * n * m - 2 * m - 2 * n)
		return printf("NO\n"), 0;
	init(n, m);
	for (auto i : v)
	{
		if (k > len(i))
		{
			if (i.first)
				ans.push_back(i), k -= len(i);
		}
		else
		{
			int di = k / i.second.size();
			int le = k % i.second.size();
			if (di)
				ans.push_back(mp(di, i.second));
			for (int j = 0; j < le; ++j)
				ans.push_back(mp(1, string(1, i.second[j])));
			break;
		}
	}
	printf("YES\n%d\n", ans.size());
	for (auto i : ans)
		printf("%d %s\n", i.first, i.second.c_str());
	return 0;
}
int main()
{
	int t = 1;
	//scanf("%d", &t);
	while (t--)
		solve();
	return 0;
}