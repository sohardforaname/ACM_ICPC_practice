#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
vector<int> G[N];
bool vis[N];
vector<int> cyc;
int dep[N];
int n, m, k;
void dfs(int u, int fa)
{
    cyc.push_back(u);
    dep[u] = dep[fa] + 1;
    for (auto i : G[u])
    {
        if (i == fa)
            continue;
        if (!dep[i])
            dfs(i, u);
        else
        {
            if (dep[u] - dep[i] + 1 >= 0 && dep[u] - dep[i] + 1 <= k)
            {
                printf("2\n%d\n", dep[u] - dep[i] + 1);
                for (int j = dep[i] - 1; j < dep[u]; ++j)
                    printf("%d%c", cyc[j], " \n"[j == dep[u] - 1]);
                exit(0);
            }
        }
    }
    if (!vis[u])
        for (auto i : G[u])
            vis[i] = 1;
    cyc.pop_back();
}
int main()
{
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 1; i <= m; ++i)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        G[u].push_back(v);
        G[v].push_back(u);
    }
    dfs(1, 0);
    printf("1\n");
    for (int i = 1, cnt = 1; i <= n && cnt <= (k + 1) / 2; ++i)
        if (!vis[i])
            printf("%d%c", i, " \n"[cnt == (k + 1) / 2]), ++cnt;
    return 0;
}