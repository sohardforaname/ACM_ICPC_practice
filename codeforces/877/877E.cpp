#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
int dfn[N], id[N], sz[N];
vector<int> G[N];
int tot;
int w[N];
void dfs(int u, int fa)
{
    dfn[u] = ++tot;
    id[tot] = u;
    sz[u] = 1;
    for (auto i : G[u])
        if (i != fa)
        {
            dfs(i, u);
            sz[u] += sz[i];
        }
}
struct segtree
{
    struct node
    {
        int l, r, sum;
        bool lazy;
    };
    node tr[N << 2];
#define ls (k << 1)
#define rs ((k << 1) + 1)
    void pushup(int k)
    {
        tr[k].sum = tr[ls].sum + tr[rs].sum;
    }
    void pushdown(int k)
    {
        if (tr[k].lazy)
        {
            tr[ls].lazy ^= tr[k].lazy;
            tr[rs].lazy ^= tr[k].lazy;
            tr[ls].sum = (tr[ls].r - tr[ls].l + 1) - tr[ls].sum;
            tr[rs].sum = (tr[rs].r - tr[rs].l + 1) - tr[rs].sum;
            tr[k].lazy = 0;
        }
    }
    void build(int l, int r, int k)
    {
        tr[k].l = l;
        tr[k].r = r;
        tr[k].lazy = 0;
        if (l == r)
        {
            tr[k].sum = w[id[l]];
            return;
        }
        int m = (l + r) >> 1;
        build(l, m, ls);
        build(m + 1, r, rs);
        pushup(k);
    }
    void update(int ql, int qr, int l, int r, int k)
    {
        if (ql <= tr[k].l && tr[k].r <= qr)
        {
            tr[k].sum = (tr[k].r - tr[k].l + 1) - tr[k].sum;
            tr[k].lazy ^= 1;
            return;
        }
        pushdown(k);
        int m = (l + r) >> 1;
        if (ql <= m)
            update(ql, qr, l, m, ls);
        if (qr > m)
            update(ql, qr, m + 1, r, rs);
        pushup(k);
    }
    int query(int ql, int qr, int l, int r, int k)
    {
        if (ql <= tr[k].l && tr[k].r <= qr)
            return tr[k].sum;
        pushdown(k);
        int ans = 0, m = (l + r) >> 1;
        if (ql <= m)
            ans += query(ql, qr, l, m, ls);
        if (qr > m)
            ans += query(ql, qr, m + 1, r, rs);
        return ans;
    }
#undef ls
#undef rs
};
segtree tr;
int main()
{
    int n, m;
    scanf("%d", &n);
    for (int i = 2; i <= n; ++i)
    {
        int p;
        scanf("%d", &p);
        G[p].push_back(i);
        G[i].push_back(p);
    }
    for (int i = 1; i <= n; ++i)
        scanf("%d", &w[i]);
    dfs(1, 0);
    tr.build(1, n, 1);
    scanf("%d", &m);
    char op[5];
    int a;
    for (int i = 1; i <= m; ++i)
    {
        scanf("%s%d", op, &a);
        if (op[0] == 'p')
            tr.update(dfn[a], dfn[a] + sz[a] - 1, 1, n, 1);
        else if (op[0] == 'g')
            printf("%d\n", tr.query(dfn[a], dfn[a] + sz[a] - 1, 1, n, 1));
    }
    return 0;
}