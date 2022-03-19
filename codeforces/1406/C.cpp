#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
vector<int> G[N];
int maxn[N], sz[N], n;
void dfs(int u, int fa)
{
    sz[u] = 1;
    maxn[u] = 0;
    for (auto i : G[u])
        if (i != fa)
        {
            dfs(i, u);
            sz[u] += sz[i];
            maxn[u] = max(maxn[u], sz[i]);
        }
    maxn[u] = max(maxn[u], n - sz[u]);
}
int find_l(int u, int fa)
{
    for (auto i : G[u])
        if (i != fa)
            return find_l(i, u);
    return u;
}
vector<int> vec;
void solve()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        G[i].clear();
    vec.clear();
    for (int i = 1; i < n; ++i)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        G[u].push_back(v);
        G[v].push_back(u);
    }
    dfs(1, 0);
    int maxa = *min_element(maxn + 1, maxn + n + 1);
    for (int i = 1; i <= n; ++i)
        if (maxn[i] == maxa)
            vec.push_back(i);
    //assert(vec.size() <= 2);
    if (vec.size() == 1)
        printf("%d %d\n%d %d\n", 1, G[1][0], 1, G[1][0]);
    else
    {
        int lef = 0;
        dfs(vec[0], 0);
        for (auto i : G[vec[0]])
            if (sz[i] < maxa)
                lef = find_l(i, vec[0]);
        printf("%d %d\n%d %d\n", lef, G[lef][0], lef, vec[1]);
    }
}
int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
        solve();
    return 0;
}
