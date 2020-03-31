#include <stdio.h>
const int maxn = 1e5 + 5;
int ans[maxn + 50];
int main()
{
	for (int i = 0; i < maxn; ++i)
	{
		int x = i, y = i;
		while (x)
			y += x % 10, x /= 10;
		if (ans[y] == 0 || i < ans[y])
			ans[y] = i;
	}
	int n, m;
	scanf("%d", &n);
	while (n--)
	{
		scanf("%d", &m);
		printf("%d\n", ans[m]);
	}
	return 0;
}