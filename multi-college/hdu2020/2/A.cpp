#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
typedef long long ll;
int fa[N], f[N];
vector<int> G[N];
pair<int, int> ver[N];
bool vis[N];
int find(int x)
{
    return x == fa[x] ? x : fa[x] = find(fa[x]);
}
bool cmp(const pair<int, int> &a, const pair<int, int> &b)
{
    return a.first > b.first;
}
int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        int n, m;
        scanf("%d%d", &n, &m);
        for (int i = 1; i <= n; ++i)
        {
            scanf("%d", &ver[i].first);
            fa[i] = ver[i].second = i;
            f[i] = vis[i] = 0;
            G[i].clear();
        }
        sort(ver + 1, ver + n + 1, cmp);
        for (int i = 1; i <= m; ++i)
        {
            int u, v;
            scanf("%d%d", &u, &v);
            G[u].push_back(v);
            G[v].push_back(u);
        }
        for (int i = 1; i <= n; ++i)
        {
            int u = ver[i].second;
            vis[u] = 1;
            for (auto v : G[u])
            {
                if (!vis[v])
                    continue;
                int fv = find(v);
                if (fv == u)
                    continue;
                fa[fv] = f[fv] = u;
            }
        }
        ll ans = 0;
        for (int i = 1; i <= n; ++i)
            ans += ver[i].first - ver[f[i]].first;
        printf("%lld\n", ans);
    }
    return 0;
}