#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5 + 5;
int a[N];
ll sum[N];
void solve()
{
    int n;
    ll m;
    scanf("%d%lld", &n, &m);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &a[i]);
    sort(a + 1, a + n + 1, greater<int>());
    for (int i = 1; i <= n; ++i)
        sum[i] = sum[i - 1] + a[i];
    ll maxn = 1;
    for (; maxn <= n && sum[maxn] / maxn >= m; ++maxn)
        ;
    printf("%lld\n", maxn - 1);
}
int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
        solve();
    return 0;
}