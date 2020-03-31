#include <iostream>
#include <string>
#include <algorithm>
#include <cstring>
#include <cstdio>
using namespace std;
struct cmd
{
	char ord[2];
	int r1, c1, r2, c2;
	int a[20], x;
};
cmd c[10000];
int ope, n, m;

int main()
{
	int n, m, k, index = 0;
	while (scanf("%d%d", &n, &m) && n + m)
	{
		if (index > 0)
			printf("\n");
		printf("Spreadsheet #%d\n", ++index);
		scanf("%d", &k);
		for (int i = 0; i < k; ++i)
		{
			getchar();
			scanf("%s", c[i].ord);
			if (c[i].ord[0] == 'E')
				scanf("%d%d%d%d", &c[i].r1, &c[i].c1, &c[i].r2, &c[i].c2);
			else
			{
				scanf("%d", &c[i].x);
				for (int j = 0; j < c[i].x; ++j)
					scanf("%d", &c[i].a[j]);
			}
		}
		int tes, x, y, x_1, y_1, tag;
		scanf("%d", &tes);
		for (int i = 0; i < tes; ++i)
		{
			tag = 0;
			scanf("%d%d", &x, &y);
			x_1 = x, y_1 = y;
			for (int j = 0; j < k; ++j)
			{
				if (c[j].ord[0] == 'E')
				{
					if (x_1 == c[j].r1&&y_1 == c[j].c1)
						x_1 = c[j].r2, y_1 = c[j].c2;
					else if (x_1 == c[j].r2&&y_1 == c[j].c2)
						x_1 = c[j].r1, y_1 = c[j].c1;
				}
				else if (c[j].ord[0] == 'D')
				{
					int minn = 0;
					if (c[j].ord[1] == 'R')
					{
						for (int p = 0; p < c[j].x; ++p)
						{
							if (x_1 == c[j].a[p])
								tag = 1;
							else if (x_1 > c[j].a[p])
								++minn;
						}
						if (tag != 1)
							x_1 -= minn;
					}
					else if (c[j].ord[1] == 'C')
					{
						for (int p = 0; p < c[j].x; ++p)
						{
							if (y_1 == c[j].a[p])
								tag = 1;
							else if (y_1 > c[j].a[p])
								++minn;
						}
						if (tag != 1)
							y_1 -= minn;
					}
				}
				else if (c[j].ord[0] == 'I')
				{
					int maxn = 0;
					if (c[j].ord[1] == 'R')
					{
						for (int p = 0; p < c[j].x; ++p)
						{
							if (x_1 >= c[j].a[p])
								++maxn;
						}
						if (tag != 1)
							x_1 += maxn;
					}
					else if (c[j].ord[1] == 'C')
					{
						for (int p = 0; p < c[j].x; ++p)
						{
							if (y_1 >= c[j].a[p])
								++maxn;
						}
						if (tag != 1)
							y_1 += maxn;
					}
				}
			}
			if (tag == 1)
				printf("Cell data in (%d,%d) GONE\n", x, y);
			else
				printf("Cell data in (%d,%d) moved to (%d,%d)\n", x, y, x_1, y_1);
		}
	}
	return 0;
}