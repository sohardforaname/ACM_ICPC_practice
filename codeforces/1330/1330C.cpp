#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5 + 5;
int a[N], ans[N];
void solve()
{
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; ++i)
        scanf("%d", &a[i]);
    int lim = n;
    for (int i = m; i; --i)
    {
        ans[i] = max(i, lim - a[i] + 1);
        lim = ans[i] - 1;
    }
    for (int i = 1; i <= m; ++i)
        if (ans[i] > n - a[i] + 1 || ans[i] < i)
        {
            printf("-1\n");
            return;
        }
    if (lim >= 1)
    {
        printf("-1\n");
        return;
    }
    for (int i = 1; i <= m; ++i)
        printf("%d%c", ans[i], " \n"[i == n]);
}
int main()
{
    int T = 1;
    //scanf("%d", &T);
    while (T--)
        solve();
    return 0;
}