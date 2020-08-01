#include <bits/stdc++.h>
using namespace std;
const int N = 8e5 + 5;
int fa[N];
inline int find(int u)
{
    int r = fa[u];
    while (fa[r] != r)
        r = fa[r];
    int t;
    while (fa[u] != r)
    {
        t = fa[u];
        fa[u] = r;
        u = t;
    }
    return r;
}
int head[N], nxt[N << 1], to[N << 1], lst[N];
int tot;
inline void add(int x, int y)
{
    to[++tot] = y;
    nxt[tot] = head[x];
    head[x] = tot;
    if (!lst[x])
        lst[x] = tot;
}
inline void init(int n)
{
    for (int i = 1; i <= n; ++i)
        fa[i] = i;
    tot = 0;
    memset(head, 0, sizeof(int) * (n + 1));
    memset(lst, 0, sizeof(int) * (n + 1));
}
inline void solve()
{
    int n, m;
    scanf("%d%d", &n, &m);
    init(n);
    for (int i = 1; i <= m; ++i)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        ++u, ++v;
        add(u, v);
        add(v, u);
    }
    int q, x;
    scanf("%d", &q);
    for (int i = 1; i <= q; ++i)
    {
        scanf("%d", &x);
        ++x;
        if (x != find(x))
            continue;
        head[0] = lst[0] = 0;
        for (int j = head[x]; j; j = nxt[j])
        {
            int fi = find(to[j]);
            if (fi == x)
                continue;
            fa[fi] = x;
            nxt[lst[fi]] = head[0];
            head[0] = head[fi];
            if (!lst[0])
                lst[0] = lst[fi];
        }
        head[x] = head[0];
        lst[x] = lst[0];
    }
    for (int i = 1; i <= n; ++i)
        printf("%d%c", find(i) - 1, " \n"[i == n]);
}
int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
        solve();
    return 0;
}