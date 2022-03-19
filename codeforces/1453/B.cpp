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
    if (n <= 2)
        return void(printf("0\n"));
    ll ans = 0;
    for (int i = 2; i <= n; ++i)
        ans += abs(a[i] - a[i - 1]);
    int maxn = 0;
    for (int i = 2; i < n; ++i)
        if ((a[i] - a[i - 1] < 0 && a[i] - a[i + 1] < 0) || (a[i] - a[i - 1] > 0 && a[i] - a[i + 1] > 0))
            maxn = max(maxn, min(abs(a[i] - a[i - 1]), abs(a[i] - a[i + 1])) * 2);
    maxn = max({maxn, abs(a[2] - a[1]), abs(a[n] - a[n - 1])});
    printf("%lld\n", ans - maxn);
}
int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
        solve();
    return 0;
}