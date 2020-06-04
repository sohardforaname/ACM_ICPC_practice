#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve()
{
    ll a, k;
    scanf("%lld%lld", &a, &k);
    for (int i = 1; i < k; ++i)
    {
        ll tmp = a;
        ll minn = 10, maxn = 0;
        while (tmp)
        {
            minn = min(minn, tmp % 10);
            maxn = max(maxn, tmp % 10);
            tmp /= 10;
        }
        if (!minn)
            break;
        a += minn * maxn;
    }
    printf("%lld\n", a);
}
int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
        solve();
    return 0;
}