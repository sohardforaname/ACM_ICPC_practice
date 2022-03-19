#include <bits/stdc++.h>
using namespace std;
int a[4];
int main()
{
	int n, sx, sy;
	int x, y;
	scanf("%d%d%d", &n, &sx, &sy);
	while (n--)
	{
		scanf("%d%d", &x, &y);
		if (x == sx)
		{
			if (y < sy)
				++a[2];
			else
				++a[3];
		}
		else if (y == sy)
		{
			if (x < sx)
				++a[0];
			else
				++a[1];
		}
		else if (x < sx && y < sy)
			++a[0], ++a[2];
		else if (x > sx && y < sy)
			++a[1], ++a[2];
		else if (x < sx && y > sy)
			++a[0], ++a[3];
		else if (x > sx && y > sy)
			++a[1], ++a[3];
	}
	int pos = max_element(a, a + 4) - a, ans = a[pos];
	if (pos == 0)
		printf("%d\n%d %d\n", ans, sx - 1, sy);
	if (pos == 1)
		printf("%d\n%d %d\n", ans, sx + 1, sy);
	if (pos == 2)
		printf("%d\n%d %d\n", ans, sx, sy - 1);
	if (pos == 3)
		printf("%d\n%d %d\n", ans, sx, sy + 1);
	return 0;
}