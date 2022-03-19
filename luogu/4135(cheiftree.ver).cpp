bool multi = 0;
const int N = 2e5 + 5;

struct node {
    int l, r, v;
} tr[N * 20];

int root[N], cnt;

vector<pair<int, int>> vec;
void update(int& rt, int lst, int l, int r, int pos, int v)
{
    rt = ++cnt; // error£¡should create install of if(!rt).
    tr[rt] = tr[lst];
    int m = (l + r) >> 1;
    if (l == r) {
        tr[rt].v = v;
        return;
    }
    if (pos <= m)
        update(tr[rt].l, tr[lst].l, l, m, pos, v);
    else
        update(tr[rt].r, tr[lst].r, m + 1, r, pos, v);
    tr[rt].v = min(tr[tr[rt].l].v, tr[tr[rt].r].v);
}
int query(int rt, int l, int r, int v)
{
    if (!rt || l == r)
        return l;
    int m = (l + r) >> 1;
    if (tr[tr[rt].l].v >= v)
        return query(tr[rt].r, m + 1, r, v);
    return query(tr[rt].l, l, m, v);
}

int a[N];
int b[N << 1];
void solve()
{
    int n, q;
    io(n, q);
    int top = 0;
    b[++top] = 0;
    for (int i = 1; i <= n; ++i) {
        io(a[i]);
        b[++top] = a[i], b[++top] = a[i] + 1;
    }
    sort(b + 1, b + top + 1);
    top = unique(b + 1, b + top + 1) - (b + 1);
    for (int i = 1; i <= n; ++i) {
        int pos = lower_bound(b + 1, b + top + 1, a[i]) - b;
        update(root[i], root[i - 1], 1, top, pos, i);
    }
    for (int i = 1; i <= q; ++i) {
        int l, r;
        io(l, r);
        io(b[query(root[r], 1, top, l)], '\n');
    }
}

MAIN_FUNC