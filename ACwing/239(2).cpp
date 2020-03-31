#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2e4 + 5;
struct op
{
	int x, y, ans;
};
op a[MAXN];
int fa[MAXN << 1];
void init()
{
	for (int i = 0; i < MAXN << 1; ++i)
		fa[i] = i;
}
int find(int x)
{
	return x == fa[x] ? x : fa[x] = find(fa[x]);
}
void join(int x, int y)
{
	x = find(x), y = find(y);
	if (x != y)
		fa[x] = y;
	find(x);
}
int b[MAXN];
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
	top = unique(b + 1, b + top + 1) - b - 1;
	for (int i = 1; i <= n; ++i)
	{
		int x = lower_bound(b + 1, b + top + 1, a[i].x) - b;
		int y = lower_bound(b + 1, b + top + 1, a[i].y) - b;
		int x_n = x + top + 1, y_n = y + top + 1;//even
		if (a[i].ans == 0)
		{
			if (find(x) == find(y_n))
			{
				printf("%d\n", i - 1);
				return 0;
			}
			join(x, y);
			join(x_n, y_n);
		}
		else if (a[i].ans == 1)
		{
			if (find(x) == find(y))
			{
				printf("%d\n", i - 1);
				return 0;
			}
			join(x_n, y);
			join(x, y_n);
		}
	}
	printf("%d\n", n);
	return 0;
}