#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 5;
long long xb[MAXN], yb[MAXN];
long long sum[MAXN];
long long calc(int n, int t, long long* arr)
{
	memset(sum, 0, sizeof(sum));
	int d = t / n;
	for (int i = 1; i <= n; ++i)
		sum[i] = sum[i - 1] + arr[i] - d;
	long long ans = 0;
	sort(sum + 1, sum + n + 1);
	int p = sum[(n + 1) / 2];
	for (int i = 1; i <= n; ++i)
		ans += abs(p - sum[i]);
	return ans;
}
int main()
{
	int n, m, t, a, b;
	scanf("%d%d%d", &n, &m, &t);
	for (int i = 1; i <= t; ++i)
	{
		scanf("%d%d", &a, &b);
		++xb[a], ++yb[b];
	}
	if (t % n == 0 && t % m == 0)
		printf("both %lld\n", calc(n, t, xb) + calc(m, t, yb));
	else if (t % n == 0)
		printf("row %lld\n", calc(n, t, xb));
	else if (t % m == 0)
		printf("column %lld\n", calc(m, t, yb));
	else
		printf("impossible\n");
	return 0;
}
