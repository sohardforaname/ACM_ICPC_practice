#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int N = 4e5 + 5;
vector<int> G[N], v;
bool vis[N];

void dfs(int u)
{
    vis[u] = 1;
    v.push_back(u);
    for (auto i : G[u])
        if (!vis[i])
            dfs(i);
}
int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        G[u].push_back(v);
        G[v].push_back(u);
    }
    int ans = 0;
    for (int i = 1; i < N; ++i)
        if (!vis[i] && G[i].size())
        {
            v.clear();
            dfs(i);
            int cnt = 0;
            for (auto j : v)
                cnt += G[j].size();
            if (cnt / 2 == v.size() - 1)
                ans += v.size() - 1;
            else
                ans += v.size();
        }
    printf("%d\n", ans);
    return 0;
}
