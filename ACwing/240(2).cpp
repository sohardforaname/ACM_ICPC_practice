#include <bits/stdc++.h>
using namespace std;
const int MAXN = 5e4 + 5;
int fa[MAXN], d[MAXN];
void init()
{
	for (int i = 0; i < MAXN; ++i)
		fa[i] = i;
}
int find(int x)
{
	if (x == fa[x])
		return x;
	int rt = find(fa[x]);
	d[x] += d[fa[x]];
	return fa[x] = rt;
}
void join(int x, int y, int k)
{
	int fx = find(x), fy = find(y);
	fa[fx] = fy;
	d[fx] = d[y] - d[x] + k;
}
int main()
{
	init();
	int n, m;
	scanf("%d%d", &n, &m);
	int op, x, y;
	int ans = 0;
	for (int i = 1; i <= m; ++i)
	{
		scanf("%d%d%d", &op, &x, &y);
		if (x > n || y > n)
		{
			++ans;
			continue;
		}
		int res = op - 1;
		int fx = find(x), fy = find(y);
		if (res && x == y)
		{
			++ans;
			continue;
		}
		else if (fx == fy)
		{
			if (((d[x] - d[y]) % 3 + 3) % 3 != res)
				++ans;
		}
		else
			join(x, y, res);
	}
	printf("%d\n", ans);
	return 0;
}