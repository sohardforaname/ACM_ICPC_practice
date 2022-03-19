#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <queue>
#include <vector>
#define pb push_back
using namespace std;
const int N = 3e5 + 10;
int n, m, ans[N], dfn[N], id[N], tot, dep[N];
int anc[N], fa[N], semi[N], mn[N], in[N], ff[20][N];
int q[N], top;
queue<int> Q;
vector<int> E[N];
struct Map
{
    struct edge
    {
        int next, to;
    } a[N << 1];
    int head[N], cnt;
    void reset()
    {
        cnt = 0;
        memset(head, 0, sizeof(head));
    }
    void link(int x, int y)
    {
        a[++cnt] = (edge){head[x], y};
        head[x] = cnt;
    }
} A, rA, B, C;
void reset()
{
    A.reset();
    rA.reset();
    B.reset();
    C.reset();
    tot = top = 0;
    for (int i = 1; i <= n; i++)
    {
        dfn[i] = id[i] = ans[i] = in[i] = anc[i] = dep[i] = 0;
        fa[i] = mn[i] = semi[i] = i;
        E[i].clear();
        for (int j = 0; j <= 18; j++)
            ff[j][i] = 0;
    }
}
void dfs(int x, int fr)
{
    dfn[x] = ++tot;
    id[tot] = x;
    anc[x] = fr;
    B.link(fr, x);
    for (int i = A.head[x]; i; i = A.a[i].next)
        if (!dfn[A.a[i].to])
            dfs(A.a[i].to, x);
}
void dfscalc(int x, int fr)
{
    ans[x] = 1;
    for (int i = C.head[x]; i; i = C.a[i].next)
        dfscalc(C.a[i].to, x), ans[x] += ans[C.a[i].to];
}
int find(int x)
{
    if (x == fa[x])
        return x;
    int tt = fa[x];
    fa[x] = find(fa[x]);
    if (dfn[semi[mn[tt]]] < dfn[semi[mn[x]]])
        mn[x] = mn[tt];
    return fa[x];
}
int LCA(int x, int y)
{
    if (dep[x] < dep[y])
        swap(x, y);
    int d = dep[x] - dep[y];
    for (int i = 18; i >= 0; i--)
        if (d & (1 << i))
            x = ff[i][x];
    for (int i = 18; i >= 0; i--)
        if (ff[i][x] ^ ff[i][y])
            x = ff[i][x], y = ff[i][y];
    return x == y ? x : ff[0][x];
}
void Work()
{
    dfs(n, 0);
    for (int w = n; w >= 2; w--)
    {
        int x = id[w], res = n;
        if (!x)
            continue;
        for (int i = rA.head[x]; i; i = rA.a[i].next)
        {
            int R = rA.a[i].to;
            if (!dfn[R])
                continue;
            if (dfn[R] < dfn[x])
                res = min(res, dfn[R]);
            else
                find(R), res = min(res, dfn[semi[mn[R]]]);
        }
        semi[x] = id[res];
        fa[x] = anc[x];
        B.link(semi[x], x);
    }

    for (int x = 1; x <= n; x++)
        for (int i = B.head[x]; i; i = B.a[i].next)
            in[B.a[i].to]++, E[B.a[i].to].pb(x);
    for (int x = 1; x <= n; x++)
        if (!in[x])
            Q.push(x);
    while (!Q.empty())
    {
        int x = Q.front();
        Q.pop();
        q[++top] = x;
        for (int i = B.head[x]; i; i = B.a[i].next)
            if (!--in[B.a[i].to])
                Q.push(B.a[i].to);
    }
    for (int i = 1; i <= top; i++)
    {
        int x = q[i], f = 0, l = E[x].size();
        if (l)
            f = E[x][0];
        for (int j = 1; j < l; j++)
            f = LCA(f, E[x][j]);
        ff[0][x] = f;
        dep[x] = dep[f] + 1;
        C.link(f, x);
        for (int p = 1; p <= 18; p++)
            ff[p][x] = ff[p - 1][ff[p - 1][x]];
    }
    ans[0] = 0;
    dfscalc(n, 0);
}
int main()
{
    cin >> n >> m;
    reset();
    for (int i = 1, x, y; i <= m; i++)
    {
        scanf("%d%d", &x, &y);
        x = n - x + 1;
        y = n - y + 1;
        A.link(x, y), rA.link(y, x);
    }
    Work();
    for (int i = n; i >= 1; i--)
        printf("%d ", ans[i]);
    return 0;
}
