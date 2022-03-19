#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2e4 + 5;
int fa[MAXN], d[MAXN];
struct op
{
	int x, y, ans;
};
op a[MAXN];
int b[MAXN];
void init()
{
	for (int i = 0; i < MAXN; ++i)
		fa[i] = i, d[i] = 0;
}
int find(int x)
{
	if (x == fa[x])
		return x;
	int rt = find(fa[x]);
	d[x] ^= d[fa[x]];
	return fa[x] = rt;
}
void join(int x, int y, int k)
{
	int fx = find(x), fy = find(y);
	if (fx != fy)
	{
		fa[fx] = fy;
		d[fx] = d[x] ^ d[y] ^ k;
	}
}
char ch[5];
int main()
{
	init();
	int n, top = 0;
	scanf("%d", &n);
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i)
	{
		scanf("%d%d%s", &a[i].x, &a[i].y, ch);
		a[i].ans = ch[0] == 'o' ? 1 : 0;
		b[++top] = (a[i].x -= 1), b[++top] = a[i].y;
	}
	sort(b + 1, b + top + 1);
	top = unique(b + 1, b + top + 1) - b;
	for (int i = 1; i <= n; ++i)
	{
		a[i].x = lower_bound(b + 1, b + top + 1, a[i].x) - b - 1;
		a[i].y = lower_bound(b + 1, b + top + 1, a[i].y) - b - 1;
		if (find(a[i].x) == find(a[i].y))
		{
			if ((d[a[i].x] ^ d[a[i].y]) != a[i].ans)
			{
				printf("%d\n", i - 1);
				return 0;
			}
		}
		else
			join(a[i].x, a[i].y, a[i].ans);
	}
	printf("%d\n", n);
	return 0;
}