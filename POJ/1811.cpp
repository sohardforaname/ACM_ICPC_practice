#include <cstdio>
#include <queue>
#include <algorithm>
#include <cmath>
using namespace std;
typedef long long ll;
const int t = 20;
ll mul(ll a, ll b, ll p)
{
	ll ans = 0;
	while (b)
	{
		if (b & 1)
			ans = (ans + a) % p;
		a = (a << 1) % p;
		b >>= 1;
	}
	return ans;
}
ll inv(ll a, ll b, ll p)
{
	ll ans = 1;
	while (b)
	{
		if (b & 1)
			ans = (ans * a) % p;
		a = (a * a) % p;
		b >>= 1;
	}
	return ans;
}
ll gcd(ll a, ll b)
{
	return b ? gcd(b, a % b) : a;
}
struct Miller
{
	bool check(ll b, ll n)
	{
		ll len = ceil(log(n - 1.0) / log(2.0)) - 1;
		ll x0 = 0, x1 = 1;
		for (int i = len; i >= 0; --i)
		{
			x0 = x1;
			x1 = mul(x1, x1, n);
			if (x1 == 1 && x0 != 1 && x0 != n - 1)
				return true;
			if (((n - 1ll) & (1ll << i)) > 0)
				x1 = mul(x1, b, n);
		}
		return x1 != 1;
	}
	int miller_rabin(ll n, int s)
	{
		for (int i = 0; i < t && i < n; ++i)
		{
			ll b = rand() % (n - 1ll) + 1;
			if (check(b, n))
				return 0;
		}
		return 1;
	}
};
Miller m;
struct Pollard
{
	queue<ll> que;
	ll pollard_rho(ll n, int c)
	{
		ll i = 1, k = 2, x = rand() % (n - 1) + 1, y = x;
		while (1)
		{
			++i;
			x = (mul(x, x, n) + c) % n;
			ll p = gcd((y - x + n) % n, n);
			if (p != 1 && p != n)
				return p;
			if (y == x)
				return n;
			if (i == k)
			{
				y = x;
				k <<= 1;
			}
		}
	}
	void find(ll n, int c)
	{
		if (n == 1)
			return;
		if (m.miller_rabin(n, t))
		{
			que.push(n);
			return;
		}
		ll p = n, k = c;
		while (p >= n)
			p = pollard_rho(p, c--);
		find(p, k);
		find(n / p, k);
	}
};
Pollard p;
int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		ll num;
		scanf("%lld", &num);
		p.find(num, 107);
		if (p.que.size() == 1)
		{
			p.que.pop();
			printf("Prime\n");
			continue;
		}
		ll minn = (1ll << 54) + 5;
		while (!p.que.empty())
		{
			minn = min(minn, p.que.front());
			p.que.pop();
		}
		printf("%lld\n", minn);
	}
	return 0;
}
