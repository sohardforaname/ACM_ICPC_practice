#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN = 1e5 + 5;
const int MAXM = 1e2 + 5;
struct Node
{
	int x, y;
	Node(int _x, int _y) :x(_x), y(_y) {}
	Node() {}
	bool operator<(const Node& a)const
	{
		return x == a.x ? y > a.y : x > a.x;//按照时间为第一关键字，等级为第二关键字
	}
};
Node a[MAXN], b[MAXN];
int num[MAXM];
int main()
{
	int n, m, x, y;
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; ++i)
		scanf("%d%d", &x, &y), a[i] = Node(x, y);
	for (int i = 1; i <= m; ++i)
		scanf("%d%d", &x, &y), b[i] = Node(x, y);
	sort(a + 1, a + n + 1);
	sort(b + 1, b + m + 1);
	ll ans = 0;
	int pos = 1, k = 0;
	for (int i = 1; i <= m; ++i)
	{
		while (pos <= n && a[pos].x >= b[i].x)
			++num[a[pos++].y];
		for (int j = b[i].y; j <= 100; ++j)
			if (num[j])
			{
				++k, --num[j];
				ans += 500 * b[i].x + 2 * b[i].y;
				break;
			}
	}
	printf("%d %lld\n", k, ans);
	return 0;
}