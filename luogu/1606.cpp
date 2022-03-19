#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 5;
typedef long long ll;
struct edge
{
    int to, w;
    bool operator<(const edge &e) const
    {
        return w > e.w;
    }
};

vector<edge> G[N];
int dis[N];
ll cnt[N];
bool vis[N];

int n, m;

bool check(int x, int y)
{
    return x >= 1 && x <= n && y >= 1 && y <= m;
}

const int dir[8][2] = {{-1, -2}, {-2, -1}, {1, -2}, {-2, 1}, {2, -1}, {-1, 2}, {1, 2}, {2, 1}};
int mp[N][N];

int getid(int x, int y)
{
    return (x - 1) * m + y;
}

void bfs(int x, int y)
{
    memset(vis, 0, sizeof(vis));
    queue<int> q;
    int id = getid(x, y);
    vis[id] = 1;
    q.push(id);
    while (q.size())
    {
        int c = q.front();
        q.pop();
        for (int i = 0; i < 8; ++i)
        {
            int xx = ((c - 1) / m + 1) + dir[i][0];
            int yy = ((c - 1) % m + 1) + dir[i][1];
            if (check(xx, yy))
            {
                int id1 = getid(xx, yy);
                if (vis[id1])
                    continue;
                vis[id1] = 1;
                if (0 == mp[xx][yy] || 4 == mp[xx][yy])
                    G[id].push_back({id1, 1});
                else if (1 == mp[xx][yy])
                    q.push(id1);
            }
        }
    }
}

void dijkstra(int s)
{
    priority_queue<edge> q;
    memset(dis, 0x3f, sizeof(dis));
    memset(vis, 0, sizeof(vis));
    q.push({s, 0});
    dis[s] = 0;
    cnt[s] = 1;
    while (q.size())
    {
        edge e = q.top();
        q.pop();
        if (vis[e.to])
            continue;
        vis[e.to] = 1;
        for (auto &i : G[e.to])
        {
            if (dis[e.to] + i.w == dis[i.to])
                cnt[i.to] += cnt[e.to];
            else if (dis[i.to] > dis[e.to] + i.w)
            {
                dis[i.to] = dis[e.to] + i.w;
                cnt[i.to] = cnt[e.to];
                q.push({i.to, dis[i.to]});
            }
        }
    }
}

int main()
{
    scanf("%d%d", &n, &m);
    int s = 0, t = 0;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
        {
            scanf("%d", &mp[i][j]);
            if (mp[i][j] == 3)
                s = getid(i, j);
            else if (mp[i][j] == 4)
                t = getid(i, j);
        }
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            if (0 == mp[i][j] || 3 == mp[i][j])
                bfs(i, j);
    dijkstra(s);
    if (0x3f3f3f3f == dis[t])
        printf("%d\n", -1);
    else
        printf("%d\n%lld\n", dis[t] - 1, cnt[t]);
    return 0;
}