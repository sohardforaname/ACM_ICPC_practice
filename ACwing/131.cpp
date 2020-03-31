#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN = 1e5 + 5;
ll a[MAXN];
stack<int>s;
int main()
{
	int n;
	while (scanf("%d", &n) && n)
	{
		while (s.size())
			s.pop();
		for (int i = 0; i < n; ++i)
			scanf("%lld", &a[i]);
		a[n] = 0;
		ll maxn = 0;
		for (int i = 0; i <= n; ++i)
		{
			while (!s.empty() && a[s.top()] > a[i])
			{
				int tmp = s.top();
				s.pop();
				maxn = max(maxn, (s.empty() ? i : i - s.top() - 1) * a[tmp]);
			}
			s.push(i);
		}
		printf("%lld\n", maxn);
	}
	return 0;
}