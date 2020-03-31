#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 5;
double num[MAXN];
double sum[MAXN];
int n, f;
double eps = 1e-5;
bool check(double avg)
{
	for (int i = 1; i <= n; ++i)
		sum[i] = sum[i - 1] + num[i] - avg;
	double maxn = -1e10;
	double minn = 1e10;
	for (int i = f; i <= n; ++i)
	{
		minn = min(minn, sum[i - f]);
		maxn = max(maxn, sum[i] - minn);
	}
	if (maxn < 0)
		return 0;
	else
		return 1;
}
int main()
{
	scanf("%d%d", &n, &f);
	for (int i = 1; i <= n; ++i)
		scanf("%lf", &num[i]);
	double l = -1e6, r = 1e6, mid;
	while (r - l > eps)
	{
		mid = (l + r) / 2;
		if (check(mid))
			l = mid;
		else
			r = mid;
	}
	printf("%d\n", int(r * 1000));
	return 0;
}
