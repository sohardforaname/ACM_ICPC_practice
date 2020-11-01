#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
struct node
{
    double x, a1, b1, a2, b2;
    node(double a, double b, double c, double d, double e)
    {
        x = a, a1 = b, a2 = c, b1 = d, b2 = e;
    }
    node() {}
} wall[25];
struct Ver
{
    int index;
    double x, y;
} ver[205];
struct edge
{
    int to;
    double w;
    edge(int a, double b)
    {
        to = a, w = b;
    }
    bool operator<(const edge &a) const
    {
        return this->w > a.w;
    }
};
vector<edge> N[205];
int pos = 0;
void read(int n)
{
    double x, a1, a2, b1, b2;
    wall[0] = node(0, 5, 5, 5, 5);
    for (int i = 1; i <= n; ++i)
    {
        cin >> x >> a1 >> a2 >> b1 >> b2;
        wall[i] = node(x, a1, a2, b1, b2);
        ver[pos].index = pos, ver[pos].x = x, ver[pos].y = a1;
        ++pos;
        ver[pos].index = pos, ver[pos].x = x, ver[pos].y = a2;
        ++pos;
        ver[pos].index = pos, ver[pos].x = x, ver[pos].y = b1;
        ++pos;
        ver[pos].index = pos, ver[pos].x = x, ver[pos].y = b2;
        ++pos;
    }
    wall[n + 1] = node(10, 5, 5, 5, 5);
}
bool check(double k, double x1, double x2, double y1, node a)
{
    double a1 = a.a1, a2 = a.a2, b1 = a.b1, b2 = a.b2;
    double y = y1 + k * (x2 - x1);
    if (y - a1 < -1e-6)
        return 0;
    else if (y - a2 > 1e-6 && y - b1 < -1e-6)
        return 0;
    else if (y - b2 > 1e-6)
        return 0;
    else
        return 1;
}
double cal(double x1, double x2, double y1, double y2)
{
    return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}
void cre(int n, int w)
{
    for (int i = 0; i < n; ++i)
        for (int j = i + 1; j < n; ++j)
        {
            if (fabs(ver[i].x - ver[j].x) < 1e-6)
                continue;
            double k = (ver[i].y - ver[j].y) / (ver[i].x - ver[j].x); //б��
            int kk = 0;
            bool flag = 0;
            for (kk = 0; wall[kk].x - ver[i].x < -1e-6 && kk < w; ++kk)
                ;
            for (kk += 1; wall[kk].x - ver[j].x < -1e-6 && kk < w; ++kk)
            {
                if (!check(k, ver[i].x, wall[kk].x, ver[i].y, wall[kk]))
                {
                    flag = 1;
                    break;
                }
            }
            if (!flag)
            {
                //cout<<i<<" "<<j<<endl;
                N[i].push_back(edge(j, cal(ver[i].x, ver[j].x, ver[i].y, ver[j].y)));
            }
        }
    /*for(int i=0;i<n;++i)
        for(int j=0;j<N[i].size();++j)
        {
            cout<<i<<" "<<N[i][j].to<<" "<<N[i][j].w<<endl;
        }*/
}
double dis[205];
bool vis[205];
void print(int n, int k)
{
    for (int i = 0; i < n; ++i)
        cout << wall[i].x << " " << wall[i].a1 << " " << wall[i].a2 << " " << wall[i].b1 << " " << wall[i].b2 << endl;
    for (int i = 0; i < k; ++i)
        cout << ver[i].index << " " << ver[i].x << " " << ver[i].y << endl;
}
void dijkstra(int n)
{
    priority_queue<edge> que;
    memset(vis, 0, sizeof(vis));
    for (int i = 0; i < 205; ++i)
        dis[i] = 999999;
    dis[0] = 0;
    que.push(edge(ver[0].index, 0));
    while (!que.empty())
    {
        edge e = que.top();
        que.pop();
        if (vis[e.to])
            continue;
        vis[e.to] = 1;
        for (int i = 0; i < N[e.to].size(); ++i)
        {
            int v = N[e.to][i].to;
            if (!vis[v])
            {
                if (dis[v] > dis[e.to] + N[e.to][i].w)
                    dis[v] = dis[e.to] + N[e.to][i].w;
                que.push(edge(v, dis[v]));
            }
        }
    }
    /*for(int i=0;i<=n;++i)
    {
        cout<<dis[i]<<endl;
    }*/
    printf("%.2f\n", dis[n - 1]);
}
int main()
{
    int n;
    cin >> n;
    ver[pos].index = pos, ver[pos].x = 0, ver[pos].y = 5;
    ++pos;
    read(n);
    n += 2;
    ver[pos].index = pos, ver[pos].x = 10, ver[pos].y = 5;
    ++pos;
    //print(n,pos);
    cre(pos, n);
    dijkstra(pos);
    return 0;
}
