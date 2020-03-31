#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN = 3e5 + 5;
deque<int>q;
ll sum[MAXN];
int a[MAXN];
int main()
{
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; ++i)
		scanf("%d", &a[i]), sum[i] = sum[i - 1] + a[i];
	ll maxn = 0;
	for (int i = 0; i <= n; ++i)
	{
		while (!q.empty() && sum[i] < sum[q.back()])
			q.pop_back();
		q.push_back(i);
		while (!q.empty() && q.front() < i - m)
			q.pop_front();
		maxn = max(maxn, sum[i] - sum[q.front()]);
	}
	printf("%lld\n", maxn);
	return 0;
}