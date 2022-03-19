#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
const int INF = 0x3f3f3f3f;
struct heap
{
    priority_queue<int> ins, del;
    int size;
    void push(int x)
    {
        ins.push(x);
        ++size;
    }
    void pop(int x)
    {
        del.push(x);
        --size;
    }
    void adj()
    {
        while (del.size() && del.top() == ins.top())
            ins.pop(), del.pop();
    }
    int top()
    {
        adj();
        return size ? ins.top() : -INF;
    }
    int cal()
    {
        if (size < 2)
            return 0;
        int x = top();
        pop(x);
        int y = top();
        push(x);
        return max(x + y, 0);
    }
    void op(int x, int ops)
    {
        ops ? push(x) : pop(x);
    }
};
heap h[N][2], ans;
struct edge
{
    int v, w;
    edge() {}
    edge(int _v, int _w) : v(_v), w(_w) {}
};
vector<edge> G[N];
int f[N][18];
int dis[N], trsize[N];
int dep[N];
int n, q;
void dfs_lca(int u, int fa)
{
    f[u][0] = fa;
    for (int i = 17; ~i; --i)
        f[u][i] = f[f[u][i - 1]][i - 1];
    dep[u] = dep[fa] + 1;
    for (auto i : G[u])
        if (i.v != fa)
        {
            dis[i.v] += dis[u] + i.w;
            dfs_lca(i.v, u);
        }
}
int get_lca(int u, int v)
{
    if (dep[u] < dep[v])
        swap(u, v);
    for (int i = 17; ~i; --i)
        if ((dep[u] - dep[v]) & (1 << i))
            u = f[u][i];
    if (u == v)
        return u;
    for (int i = 17; ~i; --i)
        if (f[u][i] != f[v][i])
            u = f[u][i], v = f[v][i];
    return f[u][0];
}
int get_dis(int x, int y)
{
    return dis[x] + dis[y] - 2 * dis[get_lca(x, y)];
}
int rt;
void getrt(int u, int fa)
{
    int maxn = 0;
    trsize[u] = 1;
}
