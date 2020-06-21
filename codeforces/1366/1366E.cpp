#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
typedef long long ll;
typedef pair<int, int> pii;
const ll mod = 998244353;
const int inf = 0X3f3f3f3f;
int a[N], b[N];
int suf[N], cnt[N];
void solve()
{
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &a[i]);
    for (int i = 1; i <= m; ++i)
        scanf("%d", &b[i]);
    suf[n + 1] = inf;
    for (int i = n; i; --i)
        suf[i] = min(suf[i + 1], a[i]);
    if (suf[1] != b[1])
    {
        printf("0\n");
        return;
    }
    for (int i = 1; i <= n; ++i)
    {
        int minn = suf[i];
        int pos = lower_bound(b + 1, b + m + 1, minn) - b;
        if (1 <= pos && pos <= m && b[pos] == minn)
            ++cnt[pos];
    }
    int ans = 1;
    for (int i = 2; i <= m; ++i)
        ans = 1ll * ans * cnt[i] % mod;
    printf("%d\n", ans);
}
int main()
{
    int T = 1;
    //scanf("%d", &T);
    while (T--)
        solve();
    return 0;
}