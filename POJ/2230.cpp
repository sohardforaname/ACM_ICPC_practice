#pragma GCC optimize(2)
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
const int N = 5e4 + 5;
bool vis[N << 1];
vector<pair<int, int>> G[N];
int cnt, ans[N << 1];
void dfs(int u)
{
    for (int i = 0; i < G[u].size(); ++i)
        if (!vis[G[u][i].second])
        {
            vis[G[u][i].second] = 1;
            dfs(G[u][i].first);
            ans[++cnt] = u;
        }
}
int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; ++i)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        G[u].push_back({v, i});
        G[v].push_back({u, i + m});
    }
    dfs(1);
    ans[0] = 1;
    for (int i = 0; i <= cnt; ++i)
        printf("%d\n", ans[i]);
    return 0;
}