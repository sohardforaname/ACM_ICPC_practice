#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
typedef long long ll;
vector<int> G[N];
int dis1[N], dis2[N], dis3[N];
int n, m, a, b, c;
int p[N];
queue<int> q;
void bfs(int s, int dis[N])
{
    dis[s] = 0;
    q.push(s);
    while (q.size())
    {
        int u = q.front();
        q.pop();
        for (auto i : G[u])
            if (dis[i] == 0x3f3f3f3f)
            {
                dis[i] = dis[u] + 1;
                q.push(i);
            }
    }
}
long long pre[N];
void solve()
{
    scanf("%d%d%d%d%d", &n, &m, &a, &b, &c);
    memset(dis1, 0x3f, sizeof(dis1[0]) * (n + 1));
    memset(dis2, 0x3f, sizeof(dis2[0]) * (n + 1));
    memset(dis3, 0x3f, sizeof(dis3[0]) * (n + 1));
    for (int i = 1; i <= n; ++i)
        G[i].clear();
    for (int i = 1; i <= m; ++i)
        scanf("%d", &p[i]);
    for (int i = 1; i <= m; ++i)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        G[u].push_back(v);
        G[v].push_back(u);
    }
    sort(p + 1, p + m + 1);
    for (int i = 1; i <= m; ++i)
        pre[i] = pre[i - 1] + p[i];
    bfs(a, dis1);
    bfs(b, dis2);
    bfs(c, dis3);
    ll ans = 0x3f3f3f3f3f3f3f3f;
    for (int i = 1; i <= n; ++i)
    {
        if (dis1[i] + dis2[i] + dis3[i] > m)
            continue;
        ans = min(ans, pre[dis2[i]] + pre[dis1[i] + dis2[i] + dis3[i]]);
    }
    printf("%lld\n", ans);
}
int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
        solve();
    return 0;
}