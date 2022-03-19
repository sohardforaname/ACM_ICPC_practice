#include <bits/stdc++.h>
#pragma GCC optimize(2)
using namespace std;
const int N = 4e5 + 5;
typedef long long ll;
ll a[N];
struct Splay
{
    ll minn[N], sum[N], val[N];
    int son[N][2], fa[N], size[N];
    int rt, sz;
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
        sum[x] = val[x];
        if (son[x][0])
        {
            size[x] += size[son[x][0]];
            minn[x] = min(minn[x], minn[son[x][0]]);
            sum[x] += sum[son[x][0]];
        }
        if (son[x][1])
        {
            size[x] += size[son[x][1]];
            minn[x] = min(minn[x], minn[son[x][1]]);
            sum[x] += sum[son[x][1]];
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
            if (fa[f] != end)
                rotate(getson(f) == getson(x) ? f : x);
            rotate(x);
        }
        pushup(x);
        if (!end)
            rt = x;
    }
    int newnode(ll x, int f)
    {
        int root = ++sz;
        val[root] = x;
        minn[root] = x;
        fa[root] = f;
        size[root] = 1;
        son[root][0] = son[root][1] = 0;
        sum[root] = 0;
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
        ++x;
        int now = rt;
        while (1)
        {
            if (!now)
                return 0;
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
    int find(int pos, ll v)
    {
        int p = kth(pos);
        splay(p, rt);
        int res = 0, now = son[rt][0];
        if (val[p] < v) //发现没这个方块直接返回这个位置
            return pos;
        while (now)
        {
            if (son[now][1] && minn[son[now][1]] < v)
                res += size[son[now][0]] + 1, now = son[now][1];
            else if (val[now] < v)
                return res + size[son[now][0]];
            else if (son[now][0] && minn[son[now][0]] < v)
                now = son[now][0];
            else
                return pos;
        }
        return pos;
    }
    ll getsum(int l, int r)
    {
        int ql = kth(l - 1), qr = kth(r + 1);
        splay(ql, rt);
        splay(qr, son[ql][1]);
        return sum[son[qr][0]];
    }
    void move(int l, int r, ll v)
    {
        int ql = kth(l - 1), qr = kth(l + 1);
        splay(ql, rt);
        splay(qr, son[ql][1]);
        int tmpv = val[son[qr][0]];
        son[qr][0] = 0;

        ql = kth(r - 1), qr = kth(r);
        splay(ql, rt);
        splay(qr, son[ql][1]);
        son[qr][0] = newnode(v, qr);
        splay(son[qr][0], rt);

        ql = kth(l - 1), qr = kth(l + 1);
        splay(ql, rt);
        splay(qr, son[ql][1]);
        val[son[qr][0]] += tmpv - v;
        splay(son[qr][0], rt);
    }
};
Splay tr;
void print(int n)
{
    for (int i = 1; i <= n; ++i)
        printf("%lld%c", tr.val[tr.kth(i)], " \n"[i == n]);
}
void solve()
{
    int n, q;
    scanf("%d%d", &n, &q);
    for (int i = 1; i <= n; ++i)
        scanf("%lld", a + i);
    a[0] = a[n + 1] = 1e18;
    tr.init();
    tr.rt = tr.build(0, 0, n + 1);
    for (int i = 1; i <= q; ++i)
    {
        int op, x, y;
        scanf("%d", &op);
        if (op == 1)
        {
            scanf("%d%d", &x, &y);
            int l = tr.find(x, y);
            if (l == x)
            {
                printf("0\n");
                continue;
            }
            printf("%lld\n", tr.getsum(l + 1, x) - (1ll * x - l) * (y - 1ll));
            tr.move(l, x, y - 1ll);
            //print(n);
        }
        else
        {
            scanf("%d", &x);
            printf("%lld\n", tr.val[tr.kth(x)]);
        }
    }
    print(n);
}
int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
        solve();
    return 0;
}