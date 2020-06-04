#include <bits/stdc++.h>
using namespace std;
const int N = 4e5 + 5;
vector<int> G[N];
int rt[N];
struct node
{
    int l, r;
    int sum, maxn;
};
node tr[N * 40];
void pushup(int rt)
{
    if (tr[tr[rt].l].sum >= tr[tr[rt].r].sum)
    {
        tr[rt].sum = tr[tr[rt].l].sum;
        tr[rt].maxn = tr[tr[rt].l].maxn;
    }
    else
    {
        tr[rt].sum = tr[tr[rt].r].sum;
        tr[rt].maxn = tr[tr[rt].r].maxn;
    }
}
int cnt;
void update(int &rt, int l, int r, int pos, int val)
{
    if (!rt)
        rt = ++cnt;
    if (l == r)
    {
        tr[rt].sum += val;
        tr[rt].maxn = pos;
        return;
    }
    int m = (l + r) >> 1;
    if (pos <= m)
        update(tr[rt].l, l, m, pos, val);
    else if (pos > m)
        update(tr[rt].r, m + 1, r, pos, val);
    pushup(rt);
}
void merge(int &lt, int rt, int l, int r)
{
    if (!lt || !rt)
    {
        lt += rt;
        return;
    }
    if (l == r)
    {
        tr[lt].sum += tr[rt].sum;
        tr[lt].maxn = max(tr[lt].maxn, tr[rt].maxn);
        return;
    }
    int m = (l + r) >> 1;
    merge(tr[lt].l, tr[rt].l, l, m);
    merge(tr[lt].r, tr[rt].r, m + 1, r);
    pushup(lt);
}
pair<int, int> ans[N];
int n, m;
void dfs(int u, int fa)
{
    for (int i = 0; i < G[u].size(); ++i)
    {
        int j = G[u][i];
        if (j != fa)
        {
            dfs(j, u);
            merge(rt[u], rt[j], 1, m);
        }
    }
    ans[u] = make_pair(tr[rt[u]].maxn, tr[rt[u]].sum);
}
int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i < n; ++i)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        G[u].push_back(v);
        G[v].push_back(u);
    }
    for (int i = 1; i <= n; ++i)
    {
        int a, b;
        scanf("%d%d", &a, &b);
        update(rt[i], 1, m, a, b);
    }
    dfs(1, 0);
    for (int i = 1; i <= n; ++i)
        printf("%d %d\n", ans[i].first, ans[i].second);
    return 0;
}