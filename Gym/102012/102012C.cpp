#include <bits/stdc++.h>
using namespace std;
const int N = 5e1 + 5;
double mp[N][N];
double dis[N][N][N];
const double INF = 1e18;
struct node
{
    int x, y, z;
    double w;
    bool operator<(const node &a) const
    {
        return w > a.w;
    }
};
priority_queue<node> q;
int n;
int h[N];
void get_mp()
{
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            if (i ^ j)
                mp[i][j] = sqrt(((i - j) * (i - j) + 1)) / (1.0 * abs(i - j));
}
void upd(int x, int y, int z, double v)
{
    if (dis[x][y][z] > v)
    {
        dis[x][y][z] = v;
        q.push({x, y, z, v});
    }
}

bool vis[N][N][N];
void dijkstra()
{
    for (int i = 0; i <= n + 1; ++i)
        for (int j = 0; j <= n + 1; ++j)
            for (int k = 0; k <= 51; ++k)
                dis[i][j][k] = INF;
    memset(vis, 0, sizeof(vis));
    while (q.size())
        q.pop();
    dis[0][n][0] = 0;
    q.push({0, n, 0, dis[0][n][0]});
    while (q.size())
    {
        node cur = q.top();
        q.pop();
        int x = cur.x, y = cur.y, z = cur.z;
        if (vis[x][y][z])
            continue;
        vis[x][y][z] = 1;
        if (x && h[x] == z)
            upd(x - 1, y, z, dis[x][y][z] + (h[x - 1] == h[x]));
        if (x < n && h[x + 1] == z)
            upd(x + 1, y, z, dis[x][y][z] + (h[x + 1] == h[x]));
        if (y && h[y] == z)
            upd(x, y - 1, z, dis[x][y][z] + (h[y - 1] == h[y]));
        if (y < n && h[y + 1] == z)
            upd(x, y + 1, z, dis[x][y][z] + (h[y + 1] == h[y]));
        if (x < n && y < n)
        {
            if (max(h[x], h[x + 1]) >= z - 1 && min(h[x], h[x + 1]) <= z - 1 &&
                max(h[y], h[y + 1]) >= z - 1 && min(h[y], h[y + 1]) <= z - 1)
                upd(x, y, z - 1, dis[x][y][z] + mp[h[x]][h[x + 1]] + mp[h[y]][h[y + 1]]);
            if (max(h[x], h[x + 1]) >= z + 1 && min(h[x], h[x + 1]) <= z + 1 &&
                max(h[y], h[y + 1]) >= z + 1 && min(h[y], h[y + 1]) <= z + 1)
                upd(x, y, z + 1, dis[x][y][z] + mp[h[x]][h[x + 1]] + mp[h[y]][h[y + 1]]);
        }
    }
    printf("%.10f\n", dis[n][0][0]);
}
void solve()
{
    scanf("%d", &n);
    for (int i = 0; i <= n; ++i)
        scanf("%d", &h[i]);
    dijkstra();
}
int main()
{
    get_mp();
    int T;
    scanf("%d", &T);
    while (T--)
        solve();
    return 0;
}