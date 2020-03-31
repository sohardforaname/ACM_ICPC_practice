#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 5;
long long num[MAXN], gap[MAXN];
int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
		scanf("%lld", &num[i]);
	gap[0] = num[0];
	for (int i = 1; i < n; ++i)
		gap[i] = num[i] - num[i - 1];
	long long p = 0, q = 0;
	for (int i = 1; i < n; ++i)
	{
		if (gap[i] > 0)
			q += gap[i];
		else if (gap[i] < 0)
			p -= gap[i];
	}
	printf("%lld\n%lld\n", max(p, q), abs(p - q) + 1);
	return 0;
}
