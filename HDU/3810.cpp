#include <bits/stdc++.h>
using namespace std;
const int N = 5e1 + 5;
struct node
{
    int c, w;
    node() {}
    node(int _c, int _w) : w(_w), c(_c) {}
    bool operator<(const node &a) const
    {
        return w == a.w ? c > a.c : w < a.w;
    }
};
node mo[N];
vector<node> G[N];
bool mp[N][N], vis[N];
priority_queue<node> q1, q2;
int n, m, ans, cnt;
void dfs(int u)
{
    vis[u] = 1;
    G[cnt].push_back(mo[u]);
    for (int i = 1; i <= n; ++i)
        if (!vis[i] && mp[u][i])
            dfs(i);
}
void divi()
{
    cnt = 0;
    memset(vis, 0, sizeof(vis));
    for (int i = 1; i <= n; ++i)
        if (!vis[i])
        {
            G[++cnt].clear();
            dfs(i);
        }
}
void solve()
{
    ans = 0x3f3f3f3f;
    node tmp;
    for (int i = 1; i <= cnt; ++i)
    {
        while (q1.size())
            q1.pop();
        while (q2.size())
            q2.pop();
        tmp.c = tmp.w = 0;
        q1.push(tmp);
        for (auto j : G[i])
        {
            while (q1.size())
            {
                tmp = q1.top();
                q1.pop();
                q2.push(tmp);
                tmp.c += j.c;
                tmp.w += j.w;
                if (tmp.w >= m)
                    ans = min(ans, tmp.c);
                if (tmp.c >= ans)
                    continue;
                q2.push(tmp);
            }
            int minc = 0x3f3f3f3f;
            while (q2.size())
            {
                tmp = q2.top();
                q2.pop();
                if (tmp.c < minc)
                {
                    minc = tmp.c;
                    q1.push(tmp);
                }
            }
        }
    }
}
int main()
{
    int T, cas = 1;
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d%d", &n, &m);
        memset(mp, 0, sizeof(mp));
        for (int i = 1; i <= n; ++i)
        {
            int k, v;
            scanf("%d%d%d", &mo[i].c, &mo[i].w, &k);
            for (int j = 1; j <= k; ++j)
            {
                scanf("%d", &v);
                mp[i][v] = mp[v][i] = 1;
            }
        }
        divi();
        solve();
        printf("Case %d: ", cas++);
        if (ans < 0x3f3f3f3f)
            printf("%d\n", ans);
        else
            printf("Poor Magina, you can't save the world all the time!\n");
    }
    return 0;
}