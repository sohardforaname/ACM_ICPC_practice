#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e3 + 5;
const double eps = 1e-7;
struct node
{
	double beg, end;
	bool operator<(const node& a)const
	{
		return beg == a.beg ? end < a.end : beg < a.beg;
	}
};
node a[MAXN];
int main()
{
	int n, m;
	scanf("%d%d", &n, &m);
	int x, y;
	bool f = 0;
	for (int i = 0; i < n; ++i)
	{
		scanf("%d%d", &x, &y);
		if (y > m)
			f = 1;
		double dis = sqrt(m * m - y * y);
		a[i].beg = x - dis, a[i].end = x + dis;
	}
	if (f)
		printf("-1\n");
	else
	{
		sort(a, a + n);
		int cnt = 1;
		double end = a[0].end;
		for (int i = 1; i < n; ++i)
		{
			if (a[i].beg <= end)
				end = min(a[i].end, end);
			else if (a[i].beg > end)
			{
				++cnt;
				end = a[i].end;
			}
		}
		printf("%d\n", cnt);
	}
	return 0;
}
