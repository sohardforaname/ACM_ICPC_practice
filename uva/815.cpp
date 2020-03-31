#include <bits/stdc++.h>
using namespace std;
const int inf = 0x7fffffff;
int h[1005];
int main()
{
	freopen("out.txt", "w", stdout);
	int n, m, cas = 0;
	while (scanf("%d%d", &n, &m) && n + m)
	{
		n *= m;
		for (int i = 0; i < n; ++i)
			scanf("%lf", &h[i]);
		double sum = 0;
		scanf("%Lf", &sum);
		sum /= 100.0;
		sort(h, h + n);
		h[n] = inf;
		int pos;
		for (pos = 1; pos <= n; ++pos)
		{
			sum += h[pos - 1];
			if (sum / pos <= h[pos])
				break;
		}
		printf("Region %d\nWater level is %.2f meters.\n%.2f percent of the region is under water.\n",
			++cas, sum / pos, pos * 100.0 / n);
		putchar('\n');
	}
	return 0;
}
