#include <stdio.h>
#include <string.h>
#include <math.h>
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
const int N = 1.1e3 + 5;
const int INF = 0x3f3f3f3f;
struct Point
{
    int x, y, z;
};
Point p[N];
struct Edge
{
    int u, v, dist;
};
Edge E[N * N];
int pre[N], vis[N], id[N];
int in[N];
int curid;
int dist(const Point &a, const Point &b)
{
    return abs(a.x - b.x) + abs(a.y - b.y) + abs(a.z - b.z);
}
ll zhuliu(int root, int n, int m)
{
    ll ret = 0;
    int u, v;
    while (true)
    {
        memset(in, 0x3f, sizeof(in[0]) * (n + 1));
        for (int i = 0; i < m; i++)
        {
            Edge &e = E[i];
            u = e.u, v = e.v;
            if (in[v] > e.dist && u != v)
            {
                pre[v] = u;
                if (u == root)
                    curid = i;
                in[v] = e.dist;
            }
        }
        for (int i = 0; i < n; i++)
            if (i != root && in[i] == INF)
                return -1;
        in[root] = 0;
        int cntcir = 0;
        memset(vis, -1, sizeof(vis));
        memset(id, -1, sizeof(id));
        for (int i = 0; i < n; i++)
        {
            ret += in[i];
            v = i;
            while (vis[v] != i && id[v] == -1 && v != root)
                vis[v] = i, v = pre[v];
            if (v != root && id[v] == -1)
            {
                for (u = pre[v]; u != v; u = pre[u])
                    id[u] = cntcir;
                id[v] = cntcir++;
            }
        }
        if (!cntcir)
            break;
        for (int i = 0; i < n; i++)
            if (id[i] == -1)
                id[i] = cntcir++;
        for (int i = 0; i < m; i++)
        {
            v = E[i].v;
            Edge &e = E[i];
            e.u = id[e.u];
            e.v = id[e.v];
            if (e.u != e.v)
                e.dist -= in[v];
        }
        n = cntcir;
        root = id[root];
    }
    return ret;
}
int main()
{
    int n, k;
    int x, y, z;
    while (~scanf("%d%d%d%d", &n, &x, &y, &z) && n + x + y + z)
    {
        int b;
        for (int i = 1; i <= n; i++)
            scanf("%d%d%d", &p[i].x, &p[i].y, &p[i].z);
        int m = 0;
        for (int i = 1; i <= n; i++)
        {
            scanf("%d", &k);
            for (int j = 1; j <= k; j++)
            {
                scanf("%d", &b);
                E[m].u = i;
                E[m].v = b;
                if (p[i].z >= p[b].z)
                    E[m++].dist = dist(p[i], p[b]) * y;
                else
                    E[m++].dist = dist(p[i], p[b]) * y + z;
            }
        }
        for (int i = 1; i <= n; i++)
        {
            E[m].u = 0;
            E[m].v = i;
            E[m++].dist = p[i].z * x;
        }
        ll res = zhuliu(0, n + 1, m);
        printf("%I64d\n", res);
    }
    return 0;
}