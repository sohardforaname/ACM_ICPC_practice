#include <bits/stdc++.h>
using namespace std;
const int N = 3e3 + 5;
typedef long long ll;
int a[N];
int cnt[N][N];
void solve()
{
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d", &a[i]);
        for (int j = 1; j <= n; ++j)
        {
            if (j == a[i])
                cnt[j][i] = cnt[j][i - 1] + 1;
            else
                cnt[j][i] = cnt[j][i - 1];
        }
    }
    ll ans = 0;
    for (int i = 2; i <= n - 2; ++i)
        for (int j = i + 1; j <= n - 1; ++j)
            ans += cnt[a[j]][i - 1] * (cnt[a[i]][n] - cnt[a[i]][j]);
    printf("%lld\n", ans);
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            cnt[i][j] = 0;
}
int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
        solve();
    return 0;
}