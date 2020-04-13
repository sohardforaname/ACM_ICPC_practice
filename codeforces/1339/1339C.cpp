#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5 + 5;
bitset<40> bit[N];
ll a[N];
void solve()
{
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        bit[i].reset();
    for (int i = 1; i <= n; ++i)
        scanf("%lld", &a[i]);
    ll maxn = -1e9 - 1;
    for (int i = 1; i <= n; ++i)
    {
        maxn = max(maxn, a[i]);
        if (maxn == a[i])
            continue;
        else
            bit[i] = maxn - a[i];
    }
    int cnt = 0;
    for (int i = 39; i >= 0; --i)
    {
        int tot = 0;
        for (int j = 1; j <= n; ++j)
            tot += bit[j][i];
        if (tot != n && tot != 0)
        {
            cnt = i + 1;
            break;
        }
    }
    printf("%d\n", cnt);
}
int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
        solve();
    return 0;
}
