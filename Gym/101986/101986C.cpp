#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5 + 5;
ll sum[N];
ll a[N];
int main()
{
    int n, t;
    scanf("%d%d", &n, &t);
    for (int i = 1; i <= n; ++i)
        scanf("%lld", &a[i]), sum[i] = sum[i - 1] + a[i];
    int maxn = 0;
    for (int i = 1; i <= n; ++i)
    {
        if (a[i] > maxn)
            maxn = a[i];
        if (t >= sum[i])
            printf("%lld\n", (t - sum[i]) / maxn + 2);
        else
            printf("%lld\n", 1ll);
    }
    return 0;
}