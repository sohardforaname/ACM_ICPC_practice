#include <bits/stdc++.h>
using namespace std;
const int MAXN = 5e4 + 5;
#define eat(x) (x + MAXN)
#define enemy(x) (x + MAXN * 2)
int fa[MAXN * 3];
void init()
{
	for (int i = 0; i < MAXN * 3; ++i)
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
			++ans;
		else if (op == 1)//同类
		{
			if (find(x) == find(eat(y)) || find(x) == find(enemy(y)))
				++ans;
			else
			{
				join(x, y);
				join(eat(x), eat(y));
				join(enemy(x), enemy(y));
			}
		}
		else if (op == 2)
		{
			if (x == y || find(x) == find(y) || find(enemy(x)) == find(y))
				++ans;
			else
			{
				join(eat(x), y);
				join(eat(y), enemy(x));
				join(enemy(y), x);
			}
		}
	}
	printf("%d\n", ans);
	return 0;
}