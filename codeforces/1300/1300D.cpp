#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
pair<double, double>p[N];
double eps = 1e-7;
#define equ(a,b) (fabs((a)-(b))<eps)
int main()
{
	int n;
	scanf("%d", &n);
	pair<double, double>c;
	for (int i = 1; i <= n; ++i)
		scanf("%lf%lf", &p[i].first, &p[i].second);
	if (n % 2)
		return printf("NO\n"), 0;
	c = { (p[1].first + p[n / 2 + 1].first) / 2,(p[1].second + p[n / 2 + 1].second) / 2 };
	for (int i = 1; i <= n / 2; ++i)
		if (!(equ((p[i].first + p[i + n / 2].first) / 2, c.first) && equ((p[i].second + p[i + n / 2].second) / 2, c.second)))
			return printf("NO\n"), 0;
	return printf("YES\n"), 0;
}