#include <bits/stdc++.h>
using namespace std;
long long gcd(long long a, long long b)
{
	return !b ? a : gcd(b, a % b);
}
long long lcm(long long a, long long b)
{
	return a / gcd(a, b) * b;
}
int main()
{
	long long sum = 0;
	scanf("%lld", &sum);
	long long a = 0, b = sum;
	long long s = sqrt(sum);
	for (long long i = s; i; --i)
		if (sum % i == 0 && lcm(i, sum / i) == sum)
			a = max(i, a), b = min(sum / i, b);
	printf("%lld %lld\n", a, b);
	return 0;
}