#include <bits/stdc++.h>
using namespace std;
long long add(long long a, long long b, long long p)
{
	long long res = 0;
	while (b)
	{
		if (b & 1)
			res = (res + a) % p;
		a = (a * 2) % p;
		b >>= 1;
	}
	return res % p;
}
int main()
{
	long long a, b, p;
	scanf("%lld%lld%lld", &a, &b, &p);
	printf("%lld\n", add(a, b, p));
	return 0;
}
