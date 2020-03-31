#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 5;
typedef long long ll;
queue<int>q1, q2, q3;
int a[MAXN];
int calc(int t, int q)
{
	int x = -0x3f, x1 = -1, x2 = -1, x3 = -1;
	if (q1.size())
		x1 = q1.front() + t * q;
	if (q2.size())
		x2 = q2.front() + t * q;
	if (q3.size())
		x3 = q3.front() + t * q;
	x = max(x1, max(x2, x3));
	if (x == x1)
		q1.pop();
	else if (x == x2)
		q2.pop();
	else if (x == x3)
		q3.pop();
	return x;
}
int main()
{
	int n, m, q, u, v, t;
	scanf("%d%d%d%d%d%d", &n, &m, &q, &u, &v, &t);
	for (int i = 1; i <= n; ++i)
		scanf("%d", &a[i]);
	sort(a + 1, a + 1 + n, greater<int>());
	for (int i = 1; i <= n; ++i)
		q1.push(a[i]);
	int ti = 1;
	while (ti <= m)
	{
		int x = calc(ti - 1, q);
		int tmp = (long long)(x) * u / v;
		q2.push(tmp - ti * q);
		q3.push(x - tmp - ti * q);
		if (ti % t == 0)
			printf("%d ", x);
		++ti;
	}
	printf("\n");
	for (int i = 1; i <= n + m; ++i)
	{
		int x = calc(m, q);
		if (i % t == 0)
			printf("%d ", x);
	}
	printf("\n");
	return 0;
}
