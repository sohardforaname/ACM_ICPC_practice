#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define min(a,b) (a<b?a:b)
const int MAXN = 1e5 + 5;
const double INF = 2e18;
struct node
{
	ll x, y;
	bool tag;
};
node a[MAXN], tmp[MAXN];
double cmp(node& a, node& b)
{
	return a.x == b.x ? a.y < b.y : a.x < b.x;
}
double cmp_y(node& a, node& b)
{
	return a.y < b.y;
}
double dist(node& a, node& b)
{
	return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}
double merge(int l, int r)
{
	auto d = INF;
	if (l == r)
		return d;
	if (l + 1 == r)
		return a[l].tag != a[r].tag ? dist(a[l], a[r]) : d;
	int m = (l + r) >> 1;
	auto d1 = merge(l, m), d2 = merge(m + 1, r);
	d = min(d1, d2);
	int top = 0;
	for (int i = l; i <= r; ++i)
		if (abs(a[i].x - a[m].x) < d)
			tmp[++top] = a[i];
	sort(tmp + 1, tmp + top + 1, cmp_y);
	for (int i = 1; i <= top; ++i)
		for (int j = i + 1; j <= top; ++j)
		{
			if (tmp[j].y - tmp[i].y >= d)
				break;
			auto t = dist(tmp[j], tmp[i]);
			if (tmp[j].tag != tmp[i].tag)
				d = min(d, t);
		}
	return d;
}
int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		int n;
		scanf("%d", &n);
		for (int i = 1; i <= n; ++i)
			scanf("%lld%lld", &a[i].x, &a[i].y), a[i].tag = 0;
		for (int i = n + 1; i <= 2 * n; ++i)
			scanf("%lld%lld", &a[i].x, &a[i].y), a[i].tag = 1;
		sort(a + 1, a + 2 * n + 1, cmp);
		printf("%.3f\n", merge(1, 2 * n));
	}
	return 0;
}