#include <algorithm>
#include <cstdio>
#include <cstdlib>
#pragma GCC optimize(2)
using namespace std;
const int N = 2e5 + 5;
int a[N];
struct Splay
{
    int minn[N], lazy[N], son[N][2], fa[N];
    int val[N], size[N];
    int rt, sz;
    bool tag[N];
    void init()
    {
        rt = sz = 0;
    }
    int getson(int x)
    {
        return son[fa[x]][1] == x;
    }
    void con(int x, int y, int z)
    {
        if (x)
            fa[x] = y;
        if (y)
            son[y][z] = x;
    }
    void pushup(int x)
    {
        if (!x)
            return;
        size[x] = 1;
        minn[x] = val[x];
        if (son[x][0])
        {
            size[x] += size[son[x][0]];
            minn[x] = min(minn[x], minn[son[x][0]]);
        }
        if (son[x][1])
        {
            size[x] += size[son[x][1]];
            minn[x] = min(minn[x], minn[son[x][1]]);
        }
    }
    void pushdown(int x)
    {
        if (tag[x])
        {
            tag[son[x][0]] ^= 1;
            tag[son[x][1]] ^= 1;
            tag[x] = 0;
            swap(son[x][0], son[x][1]);
        }
        if (lazy[x])
        {
            if (son[x][0])
            {
                lazy[son[x][0]] += lazy[x];
                val[son[x][0]] += lazy[x];
                minn[son[x][0]] += lazy[x];
            }
            if (son[x][1])
            {

                lazy[son[x][1]] += lazy[x];
                val[son[x][1]] += lazy[x];
                minn[son[x][1]] += lazy[x];
            }
            lazy[x] = 0;
        }
    }
    void rotate(int x)
    {
        int fx = fa[x], ffx = fa[fx];
        int fs = getson(x), ffs = getson(fx);
        con(son[x][fs ^ 1], fx, fs);
        con(fx, x, fs ^ 1);
        con(x, ffx, ffs);
        pushup(fx);
    }
    void splay(int x, int end)
    {
        end = fa[end];
        int f;
        while (fa[x] != end)
        {
            f = fa[x];
            pushdown(fa[f]);
            pushdown(f);
            pushdown(x);
            if (fa[f] != end)
                rotate(getson(f) == getson(x) ? f : x);
            rotate(x);
        }
        pushup(x);
        if (!end)
            rt = x;
    }
    int newnode(int x, int f)
    {
        int root = ++sz;
        val[root] = x;
        minn[root] = x;
        fa[root] = f;
        size[root] = 1;
        tag[root] = 0;
        son[root][0] = son[root][1] = 0;
        lazy[root] = 0;
        return root;
    }
    int build(int f, int l, int r)
    {
        if (l > r)
            return 0;
        int m = (l + r) >> 1;
        int tmp = newnode(a[m], f);
        son[tmp][0] = build(tmp, l, m - 1);
        son[tmp][1] = build(tmp, m + 1, r);
        pushup(tmp);
        return tmp;
    }
    int kth(int x)
    {
        int now = rt;
        while (1)
        {
            if (!now)
                return 0;
            pushdown(now);
            if (son[now][0] && x <= size[son[now][0]])
            {
                now = son[now][0];
                continue;
            }
            if (son[now][0])
                x -= size[son[now][0]];
            if (x == 1)
            {
                splay(now, rt);
                return now;
            }
            x -= 1;
            now = son[now][1];
        }
    }
    void add(int l, int r, int v)
    {
        int ql = kth(l), qr = kth(r + 2);
        splay(ql, rt), splay(qr, son[ql][1]);
        lazy[son[qr][0]] += v;
        val[son[qr][0]] += v;
        minn[son[qr][0]] += v;
        //splay(qr, rt);
    }
    int querymin(int l, int r)
    {
        int ql = kth(l), qr = kth(r + 2);
        splay(ql, rt), splay(qr, son[ql][1]);
        return minn[son[qr][0]];
    }
    void reverse(int l, int r)
    {
        int ql = kth(l), qr = kth(r + 2);
        splay(ql, rt), splay(qr, son[ql][1]);
        tag[son[qr][0]] ^= 1;
        splay(qr, rt);
    }
    void revolve(int l, int r, int k)
    {
        int t = k % (r - l + 1);
        if (t == 0)
            return;
        int ql = kth(r + 1 - t), qr = kth(r + 2);
        splay(ql, rt), splay(qr, son[ql][1]);
        int tmp = son[qr][0];
        son[qr][0] = 0;
        ql = kth(l), qr = kth(l + 1);
        splay(ql, rt), splay(qr, son[ql][1]);
        son[qr][0] = tmp;
        splay(qr, rt);
    }
    void insert(int x, int v)
    {
        int ql = kth(x + 1), qr = kth(x + 2);
        splay(ql, rt), splay(qr, son[ql][1]);
        son[qr][0] = newnode(v, qr);
        splay(qr, rt);
    }
    void dele(int x)
    {
        int ql = kth(x), qr = kth(x + 2);
        splay(ql, rt), splay(qr, son[ql][1]);
        son[qr][0] = 0;
        splay(qr, rt);
    }
    void print(int x)
    {
        pushdown(x);
        if (son[x][0])
            print(son[x][0]);
        printf("%d ", val[x]);
        if (son[x][1])
            print(son[x][1]);
    }
};
Splay tr;
int main()
{
    int n;
    scanf("%d", &n);
    a[1] = 0x3f3f3f3f;
    a[n + 2] = 0x3f3f3f3f;
    for (int i = 2; i <= n + 1; ++i)
        scanf("%d", &a[i]);
    tr.init();
    tr.rt = tr.build(0, 1, n + 2);
    int m;
    scanf("%d", &m);
    char op[5];
    for (int i = 1; i <= m; ++i)
    {
        int l, r, k;
        scanf("%s", op);
        if (op[0] == 'A')
        {
            scanf("%d%d%d", &l, &r, &k);
            tr.add(l, r, k);
        }
        else if (op[0] == 'M')
        {
            scanf("%d%d", &l, &r);
            printf("%d\n", tr.querymin(l, r));
        }
        else if (op[0] == 'R' && op[3] == 'E')
        {
            scanf("%d%d", &l, &r);
            tr.reverse(l, r);
        }
        else if (op[0] == 'R' && op[3] == 'O')
        {
            scanf("%d%d%d", &l, &r, &k);
            tr.revolve(l, r, k);
        }
        else if (op[0] == 'I')
        {
            scanf("%d%d", &l, &k);
            tr.insert(l, k);
        }
        else if (op[0] == 'D')
        {
            scanf("%d", &l);
            tr.dele(l);
        }
    }
    return 0;
}