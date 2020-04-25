#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
typedef long long ll;
int a[N];
void solve()
{
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &a[i]);
    long long ans = 0;
    bool f = 0;
    int maxn = -1e9;
    f = a[1] > 0 ? 1 : 0;
    for (int i = 1; i <= n; ++i)
    {
        if (a[i] > 0 && f)
            maxn = max(maxn, a[i]);
        else if (a[i] < 0 && !f)
            maxn = max(maxn, a[i]);
        if (a[i] < 0 && f)
            ans += maxn, maxn = a[i], f = 0;
        else if (a[i] > 0 && !f)
            ans += maxn, maxn = a[i], f = 1;
    }
    ans += maxn;
    printf("%lld\n", ans);
}
int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
        solve();
    return 0;
}
