#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
const int N = 44, M = 2e3 + 5;
vector<pair<int, int>> G[N];
int in[N], ans[M], cnt;
bool vis[M];
void dfs(int u)
{
    for (int i = 0; i < G[u].size(); ++i)
        if (!vis[G[u][i].second])
        {
            vis[G[u][i].second] = 1;
            dfs(G[u][i].first);
            ans[++cnt] = G[u][i].second;
        }
}
int main()
{
    int u, v;
    while (~scanf("%d%d", &u, &v) && u + v)
    {
        memset(in, 0, sizeof(in));
        for (int i = 1; i < N; ++i)
            G[i].clear();
        int w;
        scanf("%d", &w);
        int s = min(u, v);
        G[u].push_back({v, w});
        G[v].push_back({u, w});
        ++in[u];
        ++in[v];
        while (scanf("%d%d", &u, &v) && u + v)
        {
            scanf("%d", &w);
            G[u].push_back({v, w});
            G[v].push_back({u, w});
            ++in[u];
            ++in[v];
        }
        memset(vis, 0, sizeof(vis));
        cnt = 0;
        bool f = 0;
        for (int i = 1; i < N; ++i)
            if (in[i] % 2)
            {
                f = 1;
                break;
            }
        if (f)
        {
            printf("Round trip does not exist.\n");
            continue;
        }
        dfs(s);
        for (int i = 1; i <= cnt; ++i)
            printf("%d%c", ans[i], " \n"[i == cnt]);
    }
    return 0;
}