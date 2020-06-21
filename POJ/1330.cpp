#include <cstdio>
#include <vector>
#include <cstring>
using namespace std;
const int MAXN = 10005;
vector<int> E[MAXN];
bool vis[MAXN], rt[MAXN];
int f[MAXN];
int p, q, ans;
int find(int x)
{
    return x == f[x] ? x : f[x] = find(f[x]);
}
int join(int x, int y)
{
    int fx = find(x), fy = find(y);
    if (fx != fy)
        f[fx] = fy;
}
void dfs(int u)
{
    for (int i = 0; i < E[u].size(); ++i)
    {
        if (!vis[E[u][i]])
        {
            dfs(E[u][i]);
            join(E[u][i], u);
            vis[E[u][i]] = 1;
        }
    }
    if (u == p && vis[q])
        ans = find(q);
    if (u == q && vis[p])
        ans = find(p);
}
void init(int n)
{
    for (int i = 1; i <= n; ++i)
    {
        vis[i] = rt[i] = 0;
        f[i] = i;
        E[i].clear();
    }
}
int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        int n, a, b;
        scanf("%d", &n);
        init(n);
        for (int i = 0; i < n - 1; ++i)
        {
            scanf("%d%d", &a, &b);
            E[a].push_back(b);
            rt[b] = 1;
        }
        scanf("%d%d", &p, &q);
        for (int i = 1; i <= n; ++i)
            if (!rt[i])
                dfs(i);
        printf("%d\n", ans);
    }
    return 0;
}
