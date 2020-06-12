#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5 + 5;
vector<int> G[N];
int minn[N];
ll a[N], ans;
int b[N], c[N];
pair<ll, ll> dfs(int u, int fa, ll cost)
{
    pair<ll, ll> now;
    if (b[u] != c[u])
    {
        now.first += b[u];
        now.second += c[u];
    }
    for (auto i : G[u])
        if (i != fa)
        {
            pair<ll, ll> nxt = dfs(i, u, min(a[i], cost));
            now.first += nxt.first;
            now.second += nxt.second;
        }
    int d = min(now.first, now.second);
    ans += 2 * d * cost;
    now.first -= d;
    now.second -= d;
    return now;
}
int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        scanf("%lld%d%d", &a[i], &b[i], &c[i]);
    ll sum = 0;
    for (int i = 1; i < n; ++i)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        G[u].push_back(v);
        G[v].push_back(u);
    }
    for (int i = 1; i <= n; ++i)
        sum += b[i] - c[i];
    if (sum)
        return printf("-1\n"), 0;
    dfs(1, 0, a[1]);
    printf("%lld\n", ans);
    return 0;
}