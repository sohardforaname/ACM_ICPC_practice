#include <bits/stdc++.h>
using namespace std;
bool chk(int a, int b, int c, int ab, int bc, int ac, int abc)
{
	if (a - ab - ac + abc < 0)
		return 0;
	if (b - ab - bc + abc < 0)
		return 0;
	if (c - ac - bc + abc < 0)
		return 0;
	if (ab - abc < 0)
		return 0;
	if (ac - abc < 0)
		return 0;
	if (bc - abc < 0)
		return 0;
	if (abc < 0)
		return 0;
	return 1;
}
int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		int a, b, c, d, e, f, g;
		int n;
		scanf("%d", &n);
		int ans = 0;
		while (n--)
		{
			scanf("%d%d%d%d%d%d%d", &a, &b, &c, &d, &e, &f, &g);
			if (chk(a, b, c, d, e, f, g))
				ans = max(ans, (a + b + c - d - e - f + g));
		}
		printf("%d\n", ans);
	}
	return 0;
}