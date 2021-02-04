#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5 + 5;
int a[N], r[N];
double p[N];
bool vis[N];
void solve()
{
    int n, m;
    scanf("%d%d", &n, &m);
    memset(vis, 0, sizeof(vis[0]) * (m + 1));
    for (int i = 1; i <= n; ++i)
        scanf("%d", a + i);
    for (int i = 1; i <= m; ++i)
        scanf("%d%lf", r + i, p + i);
    if (is_sorted(a + 1, a + n + 1))
        return void(printf("1.000000\n"));
    int suf = n;
    for (int i = n; i; --i)
    {
        if (a[i] != i)
            break;
        --suf;
    }
    for (int i = 1; i <= m; ++i)
        if (r[i] >= suf)
            vis[i] = 1;
    double ans = 0, f = 1;
    for (int i = 1; i <= m; ++i)
        if (vis[i])
        {
            ans += f * p[i];
            f *= (1 - p[i]);
        }
    printf("%.6f\n", ans);
}
int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
        solve();
    return 0;
}