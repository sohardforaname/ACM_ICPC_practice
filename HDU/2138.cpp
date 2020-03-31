#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int t = 20;
bool check(ll b, ll n)
{
	int len = ceil(log(n - 1.0) / log(2.0)) - 1;
	ll x0 = 0, x1 = 1;
	for (int i = len; i >= 0; --i)
	{
		x0 = x1;
		x1 = (x1 * x1) % n;
		if (x1 == 1 && x0 != 1 && x0 != n - 1)
			return true;
		if (((n - 1) & (1 << i)) > 0)
			x1 = (x1 * b) % n;
	}
	return x1 != 1;
}
int miller_rabin(int n, int s)
{
	for (int i = 0; i < t && i < n; ++i)
	{
		ll b = rand() % (n - 1) + 1;
		if (check(b, n))
			return 0;
	}
	return 1;
}
int main()
{
	int n;
	while (~scanf("%d", &n))
	{
		int cnt = 0, num;
		for (int i = 0; i < n; ++i)
		{
			scanf("%d", &num);
			if (num % 2 == 0)
				cnt += (n == 2);
			else
				cnt += miller_rabin(num, t);
		}
		printf("%d\n", cnt);
	}
	return 0;
}
