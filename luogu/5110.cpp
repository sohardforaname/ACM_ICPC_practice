#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
const int N = 1 << 16;
const ull mod = 1e9 + 7;
const ull a = 233230706;
ull f11[N], f12[N], f21[N], f22[N];
ull pow(ull a, ull b, ull p)
{
    ull res = 1;
    while (b)
    {
        if (b & 1)
            res = res * a % p;
        a = a * a % p;
        b >>= 1;
    }
    return res;
}
void init()
{
    f11[0] = f12[0] = f21[0] = f22[0] = 1;
    int x12 = 94153035, x22 = 905847205;
    int x11 = pow(x12, N, mod), x21 = pow(x22, N, mod);
    for (int i = 1; i < N; ++i)
    {
        f11[i] = f11[i - 1] * x11 % mod;
        f12[i] = f12[i - 1] * x12 % mod;
        f21[i] = f21[i - 1] * x21 % mod;
        f22[i] = f22[i - 1] * x22 % mod;
    }
}

namespace Mker
{
    unsigned long long SA, SB, SC;
    void init()
    {
        scanf("%llu%llu%llu", &SA, &SB, &SC);
    }
    unsigned long long rand()
    {
        SA ^= SA << 32, SA ^= SA >> 13, SA ^= SA << 1;
        unsigned long long t = SA;
        SA = SB, SB = SC, SC ^= t ^ SA;
        return SC;
    }
} // namespace Mker

inline ull pow1(ull x)
{
    return f11[x >> 16] * f12[x & 65535] % mod;
}
inline ull pow2(ull x)
{
    return f21[x >> 16] * f22[x & 65535] % mod;
}

int main()
{
    init();
    int T;
    scanf("%d", &T);
    Mker::init();
    ull ans = 0, n;
    while (T--)
    {
        n = Mker::rand() % (mod - 1);
        ans ^= a * (pow1(n) + mod - pow2(n)) % mod;
    }
    printf("%llu\n", ans);
    return 0;
}