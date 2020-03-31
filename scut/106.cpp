#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100005;
struct cheiftree
{
    struct node
    {
        int l, r, sum;
    };
    node tr[MAXN * 20];
    int rt[MAXN];
    int cnt = 0;
    void init()
    {
        cnt = 0;
    }
    void build(int &rt, int l, int r)
    {
        rt = ++cnt;
        tr[rt].sum = 0;
        int m = (l + r) / 2;
        if (l == r)
            return;
        build(tr[rt].l, l, m);
        build(tr[rt].r, m + 1, r);
    }
    void update(int &rt, int l, int r, int k)
    {
        tr[++cnt] = tr[rt];
        rt = cnt;
        ++tr[rt].sum;
        if (l == r)
            return;
        int m = (l + r) / 2;
        if (k <= m)
            update(tr[rt].l, l, m, k);
        else
            update(tr[rt].r, m + 1, r, k);
    }
    int query(int rl, int rr, int l, int r, int val)
    {
        if (l == r)
            return tr[rr].sum - tr[rl].sum;
        int m = (l + r) / 2;
        if (val <= m)
            return query(tr[rl].l, tr[rr].l, l, m, val);
        else if (val > m)
            return tr[tr[rr].l].sum - tr[tr[rl].l].sum + query(tr[rl].r, tr[rr].r, m + 1, r, val);
    }
};
cheiftree tr;
int in[MAXN], a[MAXN], b[MAXN], size[MAXN], vis[MAXN];
int cnt = 0;
vector<int> E[MAXN];
void print()
{
    for (int i = 1; i <= tr.cnt; ++i)
        cout << tr.tr[i].l << " " << tr.tr[i].r << " " << tr.tr[i].sum << endl;
}
void dfs(int u)
{
    in[u] = ++cnt;
    size[u] = 1;
    vis[cnt] = u;
    for (auto &i : E[u])
    {
        dfs(i);
        size[u] += size[i];
    }
}
void init(int n)
{
    cnt = 0;
    for (int i = 1; i <= n; ++i)
        E[i].clear();
}
int main()
{
    int n, t, m;
    while (~scanf("%d%d", &n, &m))
    {
        init(n);
        for (int i = 1; i < n; ++i)
        {
            scanf("%d", &t);
            E[t].push_back(i + 1);
        }
        dfs(1);
        //for(int i=1;i<=cnt;++i)
        //cout<<in[i]<<" "<<size[i]<<" "<<vis[i]<<endl;
        for (int i = 1; i <= n; ++i)
        {
            scanf("%d", &a[i]);
            b[i] = a[i];
        }
        sort(b + 1, b + 1 + n);
        int nnew = unique(b + 1, b + 1 + n) - b - 1;
        tr.init();
        tr.build(tr.rt[0], 1, nnew);
        for (int i = 1; i <= n; ++i)
        {
            tr.rt[i] = tr.rt[i - 1];
            int pos = lower_bound(b + 1, b + 1 + nnew, a[vis[i]]) - b;
            tr.update(tr.rt[i], 1, nnew, pos);
        }
        //print();
        for (int i = 0; i < m; ++i)
        {
            scanf("%d%d", &n, &t);
            int k = upper_bound(b + 1, b + 1 + nnew, t) - b - 1;
            int l = tr.rt[in[n] - 1], r = tr.rt[in[n] + size[n] - 1];
            printf("%d\n", tr.query(l, r, 1, nnew, k));
        }
    }
    return 0;
}
