#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5 + 5;
pair<int, int> p[N];
ll sum[N];
int n;
void solve()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &p[i].first);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &p[i].second);
    sort(p + 1, p + n + 1);
    for (int i = 1; i <= n; ++i)
        sum[i] = sum[i - 1] + p[i].second;
    ll minn = sum[n];
    for (int i = 1; i <= n; ++i)
        minn = min(minn, max(1ll * p[i].first, sum[n] - sum[i]));
    printf("%lld\n", minn);
}
int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
        solve();
    return 0;
}