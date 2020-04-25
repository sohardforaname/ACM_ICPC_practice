#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5 + 5;
int a[N];
bool isp[N];
void solve()
{
    int n, k;
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &a[i]);
    memset(isp, 0, sizeof(isp[0]) * (n + 1));
    for (int i = 2; i < n; ++i)
        if (a[i - 1] < a[i] && a[i + 1] < a[i])
            isp[i] = 1;
    int ans = 0;
    for (int i = 2; i < k; ++i)
        if (isp[i])
            ++ans;
    int maxn = ans;
    int maxpos = 1;
    for (int i = k + 1; i <= n; ++i)
    {
        if (isp[i - k + 1])
            --ans;
        if (isp[i - 1])
            ++ans;
        if (ans > maxn)
            maxpos = i - k + 1;
        maxn = max(maxn, ans);
    }
    printf("%d %d\n", maxn + 1, maxpos);
}
int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
        solve();
    return 0;
}