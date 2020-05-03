#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9 + 7;
ll pre, suf;
int main()
{
    int n, k;
    scanf("%d%d", &n, &k);
    ll ans = 0;
    for (int i = k; i <= n + 1; ++i)
    {
        pre = i * (i - 1ll) / 2;
        suf = (n * 2 + 1ll - i) * i / 2;
        ans = (ans + suf - pre + 1) % mod;
    }
    printf("%lld\n", ans);
    return 0;
}