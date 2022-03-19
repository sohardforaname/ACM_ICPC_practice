#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e4 + 5;
ll d[65];
int tot;
bool flag;
void add(ll x)
{
    for (int i = 63; ~i; --i)
        if (x & (1ll << i))
        {
            if (d[i])
                x ^= d[i];
            else
            {
                d[i] = x;
                return;
            }
        }
    flag = true;
}
ll newd[65];
void init()
{
    memset(d, 0, sizeof(d));
    memset(newd, 0, sizeof(newd));
    flag = false;
    tot = 0;
}
void work()
{
    for (int i = 63; ~i; --i)
        for (int j = i - 1; ~j; --j)
            if (d[j] && d[i] & (1ll << j))
                d[i] ^= d[j];
    for (int i = 0; i < 64; ++i)
        if (d[i])
            newd[tot++] = d[i];
}
ll k_th(ll k, int n)
{
    if (flag)
        --k;
    if (!k)
        return 0;
    if (k >= (1ll << tot))
        return -1;
    ll ans = 0;
    for (int i = 63; ~i; --i)
        if (k & (1ll << i))
            ans ^= newd[i];
    return ans;
}
int main()
{
    int T;
    scanf("%d", &T);
    for (int t = 1; t <= T; ++t)
    {
        init();
        int n;
        ll a;
        scanf("%d", &n);
        for (int i = 1; i <= n; ++i)
        {
            scanf("%lld", &a);
            add(a);
        }
        printf("Case #%d:\n", t);
        work();
        int q;
        scanf("%d", &q);
        for (int i = 1; i <= q; ++i)
        {
            scanf("%lld", &a);
            printf("%lld\n", k_th(a, n));
        }
    }
    return 0;
}