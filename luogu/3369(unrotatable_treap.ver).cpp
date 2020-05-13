#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 5;
struct Treap
{
    struct node
    {
        int lc, rc, val, rnk, size;
    };
    node tr[MAXN];
    int cnt = 0;
    void init()
    {
        cnt = 0;
    }
    void pushup(int p)
    {
        tr[p].size = tr[tr[p].lc].size + tr[tr[p].rc].size + 1;
    }
    int _rand()
    {
        static int seed = int(12345);
        return seed = int(seed * 482711ll % 2147483647);
    }
    void merge(int &rt, int a, int b)
    {
        if (a == 0 || b == 0)
        {
            rt = a + b;
            return;
        }
        if (tr[a].rnk < tr[b].rnk)
            rt = a, merge(tr[rt].rc, tr[a].rc, b);
        else
            rt = b, merge(tr[rt].lc, a, tr[b].lc);
        pushup(rt);
    }
    void split(int rt, int &a, int &b, int val)
    {
        if (rt == 0)
        {
            a = b = 0;
            return;
        }
        if (tr[rt].val <= val)
            a = rt, split(tr[rt].rc, tr[a].rc, b, val);
        else
            b = rt, split(tr[rt].lc, a, tr[b].lc, val);
        pushup(rt);
    }
    int newnode(int val)
    {
        int rt = ++cnt;
        tr[rt].size = 1;
        tr[rt].val = val;
        tr[rt].lc = tr[rt].rc = 0;
        tr[rt].rnk = _rand();
        return rt;
    }
    void insert(int &rt, int val)
    {
        int x = 0, y = 0, n = newnode(val);
        split(rt, x, y, val);
        merge(x, x, n);
        merge(rt, x, y);
    }
    void del(int &rt, int val)
    {
        int x = 0, y = 0, z = 0;
        split(rt, x, y, val);
        split(x, x, z, val - 1);
        merge(z, tr[z].lc, tr[z].rc);
        merge(x, x, z);
        merge(rt, x, y);
    }
    int querynum(int rt, int rnk)
    {
        while (tr[tr[rt].lc].size + 1 != rnk)
        {
            if (tr[tr[rt].lc].size < rnk)
                rnk -= tr[tr[rt].lc].size + 1, rt = tr[rt].rc;
            else
                rt = tr[rt].lc;
        }
        return tr[rt].val;
    }
    int queryrnk(int &rt, int val)
    {
        int x = 0, y = 0;
        split(rt, x, y, val - 1);
        int tmp = tr[x].size;
        merge(rt, x, y);
        return tmp;
    }
    int queryfront(int &rt, int val)
    {
        int x = 0, y = 0;
        split(rt, x, y, val - 1);
        int tmp = querynum(x, tr[x].size);
        merge(rt, x, y);
        return tmp;
    }
    int queryback(int &rt, int val)
    {
        int x = 0, y = 0;
        split(rt, x, y, val);
        int tmp = querynum(y, 1);
        merge(rt, x, y);
        return tmp;
    }
};
Treap tr;
int p;
int main()
{
    int n;
    scanf("%d", &n);
    int m, k;
    tr.init();
    for (int i = 0; i < n; ++i)
    {
        scanf("%d%d", &m, &k);
        if (m == 1)
            tr.insert(p, k);
        else if (m == 2)
            tr.del(p, k);
        else if (m == 3)
            printf("%d\n", tr.queryrnk(p, k) + 1);
        else if (m == 4)
            printf("%d\n", tr.querynum(p, k));
        else if (m == 5)
            printf("%d\n", tr.queryfront(p, k));
        else if (m == 6)
            printf("%d\n", tr.queryback(p, k));
    }
    return 0;
}
