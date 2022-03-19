#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5 + 5;
int a[N];
bool pre[N], suf[N];
bool vis[N];
pair<int, int> ans[N];
void solve()
{
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &a[i]);
    memset(vis, 0, sizeof(vis[0]) * (n + 2));
    memset(pre, 0, sizeof(pre[0]) * (n + 2));
    memset(suf, 0, sizeof(suf[0]) * (n + 2));
    int maxn = 0;
    for (int i = 1; i <= n; ++i)
    {
        if (vis[a[i]])
            break;
        vis[a[i]] = 1;
        maxn = max(maxn, a[i]);
        if (maxn == i)
            pre[i] = 1;
    }
    memset(vis, 0, sizeof(vis[0]) * (n + 2));
    maxn = 0;
    for (int i = n; i; --i)
    {
        if (vis[a[i]])
            break;
        vis[a[i]] = 1;
        maxn = max(maxn, a[i]);
        if (maxn == n - i + 1)
            suf[i] = 1;
    }
    int cnt = 0;
    for (int i = 1; i < n; ++i)
        if (pre[i] && suf[i + 1])
        {
            ++cnt;
            ans[cnt] = make_pair(i, n - i);
        }
    printf("%d\n", cnt);
    for (int i = 1; i <= cnt; ++i)
        printf("%d %d\n", ans[i].first, ans[i].second);
}
int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
        solve();
    //system("pause");
    return 0;
}