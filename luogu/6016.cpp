#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 5e2 + 5;
const ll mod = 998244353;
ll p[N];
ll f[N];
ll ksm(ll a, ll b, ll p)
{
	ll res = 1;
	while (b)
	{
		if (b & 1)
			res = res * a % p;
		a = a * a % p;
		b >>= 1;
	}
	return res;
}
struct mat
{
	bitset<N> m[N];
};
void print(bitset<N> *bt, int n)
{
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= n; ++j)
			cout << bt[i][j] << " \n"[j == n];
}
mat G;
mat mul(const mat &a, const mat &b, int n)
{
	mat ans, tmp;
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= n; ++j)
			tmp.m[i][j] = b.m[j][i];
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= n; ++j)
			ans.m[i][j] = (a.m[i] & tmp.m[j]).any();
	return ans;
}
mat pow(mat &a, int b, int n)
{
	mat ans;
	for (int i = 1; i <= n; ++i)
		ans.m[i][i] = 1;
	while (b)
	{
		if (b & 1)
			ans = mul(ans, a, n);
		a = mul(a, a, n);
		b >>= 1;
	}
	return ans;
}
int main()
{
	int n, m;
	scanf("%d%d", &n, &m);
	int ai, tp;
	for (int i = 1; i <= n; ++i)
	{
		f[i] = 1;
		scanf("%lld%d", &p[i], &ai);
		for (int j = 1; j <= ai; ++j)
		{
			scanf("%d", &tp);
			G.m[tp][i] = 1;
		}
	}
	if (m == 0)
	{
		ll ans = 0;
		for (int i = 1; i <= n; ++i)
			(ans += (p[i] + mod)) %= mod;
		printf("%lld\n", ans);
	}
	else
	{
		G = pow(G, m, n);
		ll ans = 0;
		for (int i = 1; i <= n; ++i)
			for (int j = 1; j <= n; ++j)
				if (G.m[i][j])
					f[j] = (f[j] * (1 - p[i]) + mod) % mod;
		for (int i = 1; i <= n; ++i)
			(ans += (1 - f[i] + mod)) %= mod;
		printf("%lld", ans);
	}
	return 0;
}