#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int b[N];
int main()
{
	int n, l, r;
	while (scanf("%d", &n) && n)
	{
		memset(b, 0, sizeof(b[0]) * (n + 1));
		for (int i = 1; i <= n; ++i)
		{
			scanf("%d%d", &l, &r);
			++b[l], --b[r + 1];
		}
		for (int i = 1; i <= n; ++i)
			printf("%d%c", (b[i] += b[i - 1]), " \n"[i == n]);
	}
	return 0;
}