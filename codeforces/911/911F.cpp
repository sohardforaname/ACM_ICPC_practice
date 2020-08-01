#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
int dep[N];
int t1, t2;
vector<int> G[N];
int f[N][20];
typedef long long ll;
void dfs(int u, int fa)
{
    dep[u] = dep[fa] + 1;
    f[u][0] = fa;
    for (int i = 1; i < 20; ++i)
        f[u][i] = f[f[u][i - 1]][i - 1];
    for (auto i : G[u])
        if (i != fa)
            dfs(i, u);
}
int get_lca(int u, int v)
{
    if (dep[u] < dep[v])
        swap(u, v);
    for (int i = 19; ~i; --i)
        if (1 << i & (dep[u] - dep[v]))
            u = f[u][i];
    if (u == v)
        return u;
    for (int i = 19; ~i; --i)
        if (f[u][i] != f[v][i])
        {
            u = f[u][i];
            v = f[v][i];
        }
    return f[u][0];
}
vector<pair<int, int>> ans;
int in[N];
int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 1; i < n; ++i)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        G[u].push_back(v);
        G[v].push_back(u);
    }
    dfs(1, 0);
    t1 = max_element(dep + 1, dep + n + 1) - dep;
    dfs(t1, 0);
    t2 = max_element(dep + 1, dep + n + 1) - dep;
    ll cnt = 0;
    queue<int> q;
    for (int i = 1; i <= n; ++i)
        in[i] = G[i].size();
    for (int i = 1; i <= n; ++i)
        if (i != t1 && i != t2 && in[i] == 1)
            q.push(i);
    while (q.size())
    {
        int cur = q.front();
        q.pop();
        int lca = get_lca(cur, t2);
        if (dep[lca] <= (dep[t2] + 1) / 2)
        {
            cnt += dep[t2] + dep[cur] - dep[lca] * 2;
            ans.push_back({cur, t2});
        }
        else
        {
            cnt += dep[cur] - dep[t1];
            ans.push_back({cur, t1});
        }
        for (auto i : G[cur])
        {
            --in[i];
            if (in[i] == 1)
                q.push(i);
        }
    }
    int tmp = t2;
    for (int i = 1; i < dep[t2]; ++i)
    {
        ans.push_back({tmp, t1});
        tmp = f[tmp][0];
    }
    printf("%lld\n", cnt + 1ll * dep[t2] * (dep[t2] - 1) / 2);
    for (auto &i : ans)
        printf("%d %d %d\n", i.first, i.second, i.first);
    return 0;
}