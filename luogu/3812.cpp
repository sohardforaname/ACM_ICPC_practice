#include <bits/stdc++.h>
using namespace std;
const int N = 5e1 + 5;
typedef long long ll;
ll a[N], d[N];
void add(ll x)
{
    for (int i = 54; i >= 0; --i)
        if (x & (1ll << i))
        {
            if (d[i])
                x ^= d[i];
            else
            {
                d[i] = x;
                break;
            }
        }
}
int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        scanf("%lld", &a[i]), add(a[i]);
    ll ans = 0;
    for (int i = 54; i >= 0; --i)
        if (d[i] && (ans ^ d[i]) > ans)
            ans ^= d[i];
    printf("%lld\n", ans);
    return 0;
}