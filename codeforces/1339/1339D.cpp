#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5 + 5;
vector<int> G[N];
vector<int> le;
int dep[N];
void dfs(int u, int fa)
{
    dep[u] = dep[fa] + 1;
    for (auto i : G[u])
        if (!dep[i])
            dfs(i, u);
}
void solve()
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
    dfs(1, 0); //树根深度为1
    for (int i = 1; i <= n; ++i)
        if (G[i].size() == 1)
            le.push_back(i);
    int ecnt = 0;
    for (int i = 0; i < le.size(); ++i)
        if (dep[le[i]] % 2 == 1)
            ++ecnt;
    if (ecnt == le.size() || ecnt == 0)
        printf("1 ");
    else
        printf("3 ");
    int cnt = n - 1;
    for (int i = 1; i <= n; ++i)
    {
        int tot = 0;
        for (auto j : G[i])
            tot += (G[j].size() == 1);
        if (tot >= 2)
            cnt -= tot - 1;
    }
    printf("%d\n", cnt);
}
int main()
{
    int T = 1;
    //scanf("%d", &T);
    while (T--)
        solve();
    return 0;
}