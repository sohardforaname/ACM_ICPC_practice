#include <bits/stdc++.h>
#define min(a,b) (a<b?a:b)
using namespace std;
typedef long long ll;
const int MAXN = 2e5 + 5;
const double INF = 2e18;
struct Node
{
	ll x, y;
};
Node a[MAXN], tmp[MAXN];
bool cmp(Node& x, Node& y)
{
	return x.x == y.x ? x.y < y.y : x.x < y.x;
}
bool cmp_y(Node& x, Node& y)
{
	return x.y < y.y;
}
double dist(Node& x, Node& y)
{
	return sqrt((x.x - y.x) * (x.x - y.x) + (x.y - y.y) * (x.y - y.y));
}
double merge(int l, int r)
{
	if (l == r)
		return INF;
	if (r - l == 1)
		return dist(a[r], a[l]);
	int m = (l + r) >> 1;
	auto d = INF;
	auto d1 = merge(l, m), d2 = merge(m + 1, r);
	d = min(d1, d2);
	int top = 0;
	for (int i = l; i <= r; ++i)
		if (abs(a[i].x - a[m].x) <= d)
			tmp[++top] = a[i];
	sort(tmp + 1, tmp + top + 1, cmp_y);
	for (int i = 1; i <= top; ++i)
		for (int j = i + 1; j <= top; ++j)
		{
			if (tmp[j].y - tmp[i].y >= d)
				break;
			auto t = dist(tmp[j], tmp[i]);
			d = min(d, t);
		}
	return d;
}
int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i)
		scanf("%lld%lld", &a[i].x, &a[i].y);
	sort(a + 1, a + n + 1, cmp);
	printf("%.4f\n", merge(1, n));
	return 0;
}