#include <bits/stdc++.h>
using namespace std;
long long inv(long long a, long long b, long long p)
{
    long long res = 1;
    while (b) {
        if (b & 1)
            res = (res * a) % p;
        a = (a * a) % p;
        b >>= 1;
    }
    return res % p;
}
int main()
{
    long long a, b, p;
    scanf("%lld%lld%lld", &a, &b, &p);
    printf("%lld\n", inv(a, b, p));
    return 0;
}
