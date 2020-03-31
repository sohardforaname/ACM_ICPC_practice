#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
#define Tree 8005
int now;
struct Segtree
{
    int vis[8005];
    struct node
    {
        int l, r, val;
    } tr[Tree * 4];
    void down(int k)
    {
        tr[k * 2].val = tr[k].val;
        tr[k * 2 + 1].val = tr[k].val;
        tr[k].val = -1;
    }
    void clean()
    {
        for (int i = 0; i < Tree * 4; ++i)
            tr[i].val = -1;
        memset(vis, 0, sizeof(vis));
    }
    void build(int l, int r, int k)
    {
        tr[k].l = l, tr[k].r = r, tr[k].val = -1;
        if (l == r)
            return;
        int m = (l + r) / 2;
        build(l, m, k * 2);
        build(m + 1, r, k * 2 + 1);
    }
    void update(int l, int r, int k, int val)
    {
        if (l <= tr[k].l && r >= tr[k].r)
        {
            tr[k].val = val;
            return;
        }
        //if(tr[k].val==val)
        //return;
        if (tr[k].val != -1)
            down(k);
        tr[k].val = -1;
        int m = (tr[k].l + tr[k].r) / 2;
        if (l <= m)
            update(l, r, k * 2, val);
        if (r >= m + 1)
            update(l, r, k * 2 + 1, val);
    }
    void query(int k)
    {
        if (tr[k].l == tr[k].r)
        {
            if (tr[k].val != -1 && tr[k].val != now)
                ++vis[tr[k].val];
            now = tr[k].val;
            return;
        }
        if (tr[k].val != -1)
            down(k);
        query(k * 2);
        query(k * 2 + 1);
    }
};
Segtree seg;
int main()
{
    int n, a, b, c;
    seg.build(1, 8001, 1);
    while (cin >> n)
    {
        seg.clean();
        for (int i = 0; i < n; ++i)
        {
            cin >> a >> b >> c;
            if (a < b)
                seg.update(a + 1, b, 1, c);
        }
        now = -1;
        seg.query(1);
        for (int i = 0; i < 8005; ++i)
            if (seg.vis[i])
                cout << i << " " << seg.vis[i] << endl;
        cout << endl;
    }
    return 0;
}
