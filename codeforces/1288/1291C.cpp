#include <bits/stdc++.h>
using namespace std;
int a[3505], b[3005];
deque<int>que;
int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		int n, m, k;
		scanf("%d%d%d", &n, &m, &k);
		for (int i = 1; i <= n; ++i)
			scanf("%d", &a[i]);
		if (k >= m)
			k = m - 1;
		for (int i = 0; i < m; ++i)
			b[i] = max(a[i + 1], a[n - m + i + 1]);
		while (que.size())
			que.pop_front();
		for (int i = 0; i <= m - k - 1; ++i)
		{
			while (que.size() && b[que.back()] > b[i])
				que.pop_back();
			que.push_back(i);
		}
		int maxn = b[que.front()];
		for (int i = m - k; i < m; ++i)
		{
			while (que.size() && b[que.back()] > b[i])
				que.pop_back();
			while (que.size() && que.front() <= i - m + k)
				que.pop_front();
			que.push_back(i);
			maxn = max(maxn, b[que.front()]);
		}
		printf("%d\n", maxn);
	}
	return 0;
}