#include <bits/stdc++.h>
using namespace std;
const int N = 1e2 + 5;
vector<int> G[N];

bool dir[N][N];
vector<pair<int, int>> e;
bool vis[N];
int cnt[N];

void dfs(int u)
{
    vis[u] = 1;
    for (auto v : G[u])
    {
        if (cnt[u] > cnt[v])
            dir[u][v] = 1;
        else if (cnt[u] == cnt[v])
        {
            if (!vis[v])
            {
                dir[u][v] = 1;
                dfs(v);
            }
            else if (!dir[v][u])
                dir[u][v] = 1;
        }
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
        G[u].push_back(v);
        G[v].push_back(u);
        e.push_back({u, v});
    }
    for (int i = 1; i <= n; ++i)
        scanf("%d", &cnt[i]);

    for (int i = 1; i <= n; ++i)
        if (!vis[i])
            dfs(i);

    for (auto &i : e)
        printf("%s\n", dir[i.first][i.second] ? "->" : "<-");

    return 0;
}