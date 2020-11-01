#include <bits/stdc++.h>
using namespace std;
const int N = 6e2 + 5;
struct seg
{
    int x1, y1, x2, y2;
};
struct node
{
    int x, y;
};

node w[N];
seg s[N];
int cnt;

double dist(int x_1, int y_1, int x_2, int y_2)
{
    return sqrt((x_1 - x_2) * (x_1 - x_2) + (y_1 - y_2) * (y_1 - y_2));
}
int n, m, k;

struct edge
{
    int to;
    double w;
    bool operator<(const edge &a) const
    {
        return w > a.w;
    }
};
vector<edge> G[N << 1];

int cross(int x_1, int y_1, int x_2, int y_2)
{
    return x_1 * y_2 - y_1 * x_2;
}

bool intersection(node a1, node a2, node b1, node b2)
{
    int c1 = cross(a2.x - a1.x, a2.y - a1.y, b1.x - a1.x, b1.y - a1.y);
    int c2 = cross(a2.x - a1.x, a2.y - a1.y, b2.x - a1.x, b2.y - a1.y);
    int c3 = cross(b2.x - b1.x, b2.y - b1.y, a1.x - b1.x, a1.y - b1.y);
    int c4 = cross(b2.x - b1.x, b2.y - b1.y, a2.x - b1.x, a2.y - b1.y);
    return 1ll * c1 * c2 < 0 && 1ll * c3 * c4 < 0;
}

double dis[N];
bool vis[N];

void dijkstra()
{
    priority_queue<edge> q;
    memset(vis, 0, sizeof(vis));
    for (int i = 0; i <= cnt; ++i)
        dis[i] = 1e18;
    dis[cnt - 1] = 0;
    q.push({cnt - 1, 0});
    while (q.size())
    {
        edge cur = q.top();
        q.pop();
        if (vis[cur.to])
            continue;
        vis[cur.to] = 1;
        for (auto i : G[cur.to])
            if (dis[i.to] > dis[cur.to] + i.w)
            {
                dis[i.to] = dis[cur.to] + i.w;
                q.push({i.to, dis[i.to]});
            }
    }
}

void solve()
{
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 1; i <= k; ++i)
    {
        scanf("%d%d%d%d", &s[i].x1, &s[i].y1, &s[i].x2, &s[i].y2);
        w[++cnt].x = s[i].x1, w[cnt].y = s[i].y1;
        w[++cnt].x = s[i].x2, w[cnt].y = s[i].y2;
    }
    int X1, Y1, X2, Y2;
    scanf("%d%d%d%d", &X1, &Y1, &X2, &Y2);
    w[++cnt] = {X1, Y1};
    w[++cnt] = {X2, Y2};
    for (int i = 1; i <= cnt; ++i)
        for (int j = i + 1; j <= cnt; ++j)
        {
            bool isinter = 0;
            for (int l = 1; l <= k; ++l)
                if (intersection(w[i], w[j], node({s[l].x1, s[l].y1}), node({s[l].x2, s[l].y2})))
                {
                    isinter = 1;
                    break;
                }
            if (isinter)
                continue;
            double dis = dist(w[i].x, w[i].y, w[j].x, w[j].y);
            G[i].push_back({j, dis});
            G[j].push_back({i, dis});
        }
    dijkstra();
    printf("%.4lf\n", dis[cnt]);
}

int main()
{
    solve();
    return 0;
}