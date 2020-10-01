#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5 + 5;
int a[N], minn[N], d[N];
ll sum[N];
int main()
{
    int n, k;
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &a[i]);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &d[i]);
    minn[0] = 0x3f3f3f3f;
    for (int i = 1; i <= n; ++i)
    {
        sum[i] = sum[i - 1] + a[i];
        minn[i] = min(minn[i - 1], d[i]);
    }
    if (k == 0)
    {
        ll ans = 0;
        for (int i = 1; i <= n; ++i)
            ans = max(ans, sum[n] - sum[i - 1] - d[i]);
        printf("%lld\n", ans);
    }
    else if (k > 1)
    {
        ll ans = 0;
        for (int i = 1; i < n; ++i)
            ans = max(ans, sum[n] - d[i]);
        ans = max(ans, 0ll + a[n] - d[n]);
        printf("%lld\n", ans);
    }
    else
    {
        ll ans = 0;
        for (int i = 2; i <= n; ++i)
            ans = max(ans, sum[n] - minn[i - 1] - d[i]);
        for (int i = 2; i <= n; ++i)
            ans = max(ans, sum[n] - sum[i - 1] - d[i]);

        for (int i = 2; i <= n; ++i)
            ans = max(ans, sum[n] - d[i] - d[1]);
        for (int i = 2; i <= n; ++i)
            ans = max(ans, sum[n] - a[i] - d[1]);
        ans = max(ans, sum[n - 1] - minn[n - 1]);
        printf("%lld\n", ans);
    }
    return 0;
}