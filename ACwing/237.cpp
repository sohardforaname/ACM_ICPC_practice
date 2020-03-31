#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2e6 + 5;
int b[MAXN];
struct node
{
	int a, b, c;
	bool operator<(const node& a)const
	{
		return c > a.c;
	}
};
node a[MAXN];
int fa[MAXN];
void init(int n)
{
	for (int i = 0; i <= 2 * n; ++i)
		fa[i] = i;
}
int find(int x)
{
	return x == fa[x] ? x : fa[x] = find(fa[x]);
}
void uni(int x, int y)
{
	int fx = find(x), fy = find(y);
	if (fx != fy)
		fa[fx] = fy;
	find(fx);
}
int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		int n, top = 0;
		scanf("%d", &n);
		init(n);
		for (int i = 1; i <= n; ++i)
		{
			scanf("%d%d%d", &a[i].a, &a[i].b, &a[i].c);
			b[++top] = a[i].a, b[++top] = a[i].b;
		}
		sort(b + 1, b + top + 1);
		top = unique(b + 1, b + top + 1) - b;
		for (int i = 1; i <= n; ++i)
		{
			a[i].a = lower_bound(b + 1, b + top + 1, a[i].a) - b;
			a[i].b = lower_bound(b + 1, b + top + 1, a[i].b) - b;
		}
		sort(a + 1, a + n + 1);
		bool f = 1;
		for (int i = 1; i <= n; ++i)
		{
			if (a[i].c == 1)
				uni(a[i].a, a[i].b);
			else if (a[i].c == 0)
				if (find(a[i].a) == find(a[i].b))
				{
					f = 0;
					break;
				}
		}
		printf("%s\n", f ? "YES" : "NO");
	}
	return 0;
}