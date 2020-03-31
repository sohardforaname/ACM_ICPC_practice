#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 5e5 + 5;
ll dp[N];
ll sum[N], a[N];
int q[N];
ll getx(int i, int j)
{
	return sum[j] - sum[i];
}
ll gety(int i, int j)
{
	return dp[j] + sum[j] * sum[j] - dp[i] - sum[i] * sum[i];
}
int main()
{
	int n;
	ll m;
	while (~scanf("%d%lld", &n, &m))
	{
		for (int i = 1; i <= n; ++i)
			scanf("%lld", &a[i]), sum[i] = sum[i - 1] + a[i];
		int head = 1, tail = 1;
		q[tail++] = 0;
		for (int i = 1; i <= n; ++i)
		{
			while (head < tail - 1 && gety(q[head], q[head + 1]) <= 2 * sum[i] * getx(q[head], q[head + 1]))
				++head;
			dp[i] = dp[q[head]] + (sum[i] - sum[q[head]]) * (sum[i] - sum[q[head]]) + m;
			while (head < tail - 1 && gety(q[tail - 2], q[tail - 1]) * getx(q[tail - 1], i) >= gety(q[tail - 1], i) * getx(q[tail - 2], q[tail - 1]))
				--tail;
			q[tail++] = i;
		}
		printf("%lld\n", dp[n]);
	}
    return 0;
}