#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
const int MAXN = 1e6 + 5;
const int base = 13331;
ull sum[MAXN], p[MAXN];
char str[MAXN];
ull geths(int l, int r)
{
	return sum[r] - sum[l - 1] * p[r - l + 1];
}
int main()
{
	scanf("%s", str + 1);
	int len = strlen(str + 1);
	p[0] = 1;
	for (int i = 1; i <= len; ++i)
	{
		p[i] = p[i - 1] * base;
		sum[i] = sum[i - 1] * base + (str[i] - 'a');
	}
	int m;
	scanf("%d", &m);
	int l1, l2, r1, r2;
	for (int i = 1; i <= m; ++i)
	{
		scanf("%d%d%d%d", &l1, &r1, &l2, &r2);
		if (geths(l1, r1) == geths(l2, r2))
			printf("Yes\n");
		else
			printf("No\n");
	}
}