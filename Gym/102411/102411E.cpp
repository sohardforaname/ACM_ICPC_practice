#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
vector<int> G[N];
int w[N], cnt[N], dis[N];
int bfs(int m)
{
    queue<int> q;
    for (int i = 1; i <= m; ++i)
    {
        q.push(w[i]);
        ++cnt[w[i]];
        dis[w[i]] = 1;
    }
    while (q.size())
    {
        int cur = q.front();
        q.pop();
        if (cnt[cur] == m)
            return cur;
        for (auto i : G[cur])
            if (!dis[i] || dis[i] == dis[cur] + 1)
            {
                if (!dis[i])
                    q.push(i);
                dis[i] = dis[cur] + 1;
                cnt[i] += cnt[cur];
            }
    }
    return 0;
}
int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 1; i < n; ++i)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        G[u].push_back(v);
        G[v].push_back(u);
    }
    for (int i = 1; i <= m; ++i)
        scanf("%d", &w[i]);
    int ans = bfs(m);
    if (ans)
        printf("YES\n%d\n", ans);
    else
        printf("NO\n");
    return 0;
}