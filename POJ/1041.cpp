#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;
const int N = 50;
const int M = 2e3 + 5;
int G[N][M];
bool vis[M];
int ans[M], in[N];
int cnt;
int maxe, maxv;
void dfs(int u)
{
    for (int i = 1; i <= maxe; ++i)
        if (!vis[i] && G[u][i])
        {
            vis[i] = 1;
            dfs(G[u][i]);
            ans[++cnt] = i;
        }
}
int main()
{
    int u, v, w;
    while (~scanf("%d%d", &u, &v) && u + v)
    {
        int s = min(u, v);
        memset(in, 0, sizeof(in));
        memset(G, 0, sizeof(G));
        maxe = 0, maxv = 0;
        scanf("%d", &w);
        G[u][w] = v;
        G[v][w] = u;
        ++in[u], ++in[v];
        maxe = max(maxe, w);
        maxv = max(maxv, u);
        maxv = max(maxv, v);
        while (scanf("%d%d", &u, &v) && u + v)
        {
            scanf("%d", &w);
            G[u][w] = v;
            G[v][w] = u;
            ++in[u], ++in[v];
            maxe = max(maxe, w);
            maxv = max(maxv, u);
            maxv = max(maxv, v);
        }
        memset(vis, 0, sizeof(vis));
        cnt = 0;
        bool f = 0;
        for (int i = 1; i <= maxv; ++i)
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