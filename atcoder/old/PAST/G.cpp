#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 6e2 + 5;
int dis[N * N];
bool vis[N * N];
vector<int> G[N * N];
bool mp[N][N];
int dir[6][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}, {1, 1}, {-1, 1}};
#define p(x, y) ((x)*601 + (y))
struct edge
{
    int v, w;
    edge() {}
    edge(int _v, int _w) : v(_v), w(_w) {}
    bool operator<(const edge &a) const
    {
        return w > a.w;
    }
};
bool check(int x, int y)
{
    if (x >= 0 && x <= 600 && y >= 0 && y <= 600 && !mp[x][y])
        return 1;
    return 0;
}
void solve()
{
    int n, x, y;
    scanf("%d%d%d", &n, &x, &y);
    for (int i = 1; i <= n; ++i)
    {
        int xx, yy;
        scanf("%d%d", &xx, &yy);
        mp[xx + 300][yy + 300] = 1;
    }
    for (int i = 0; i <= 600; ++i)
        for (int j = 0; j <= 600; ++j)
            for (int k = 0; k < 6; ++k)
            {
                int xx = i + dir[k][0], yy = j + dir[k][1];
                if (check(xx, yy))
                    G[p(i, j)].push_back(p(xx, yy));
            }
    priority_queue<edge> q;
    memset(dis, 0x3f, sizeof(dis));
    q.push({p(300, 300), 0});
    dis[p(300, 300)] = 0;
    while (q.size())
    {
        auto cur = q.top();
        q.pop();
        if (vis[cur.v])
            continue;
        vis[cur.v] = 1;
        for (auto &i : G[cur.v])
            if (dis[i] > dis[cur.v] + 1)
            {
                dis[i] = dis[cur.v] + 1;
                q.push({i, dis[i]});
            }
    }
    if (dis[p(x + 300, y + 300)] == 0x3f3f3f3f)
        printf("-1\n");
    else
        printf("%d\n", dis[p(x + 300, y + 300)]);
}
int main()
{
    int T = 1;
    //scanf("%d", &T);
    while (T--)
        solve();
    return 0;
}