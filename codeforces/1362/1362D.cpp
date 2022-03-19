#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 5;
vector<int> G[N];
struct node
{
    int v, id;
    bool operator<(const node &a) const
    {
        return id == a.id ? v < a.v : id < a.id;
    }
};
int maxn[N];
node e[N];
vector<int> ans;
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
    }
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d", &e[i].id);
        e[i].v = i;
    }
    for (int i = 1; i <= n; ++i)
        for (auto j : G[i])
            if (e[i].id == e[j].id)
                return printf("-1\n"), 0;
    sort(e + 1, e + n + 1);
    for (int i = 1; i <= n; ++i)
    {
        int v = e[i].v;
        if (e[i].id == maxn[v] + 1)
        {
            maxn[v] = e[i].id;
            ans.push_back(v);
            for (auto u : G[v])
                if (maxn[v] == maxn[u] + 1)
                    maxn[u] = maxn[v];
        }
        else
            return printf("-1\n"), 0;
    }
    for (int i = 0; i < ans.size(); ++i)
        printf("%d%c", ans[i], " \n"[i == ans.size() - 1]);
    return 0;
}