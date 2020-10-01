#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
struct BIT
{
    int c[N];
    void update(int pos, int val, int n)
    {
        for (; pos <= n; pos += (pos & -pos))
            c[pos] += val;
    }
    int query(int pos, int n)
    {
        int ans = 0;
        for (; pos; pos -= (pos & -pos))
            ans += c[pos];
        return ans;
    }
    int sum(int l, int r, int n)
    {
        return query(r, n) - query(l - 1, n);
    }
};
namespace reader
{
    const int MAXBUF = 1 << 20;
    char buf[1 << 20], *fh = NULL, *ft = NULL;
    inline char gc()
    {
        if (fh == ft)
        {
            int l = fread(buf, 1, MAXBUF, stdin);
            ft = (fh = buf) + l;
        }
        return *fh++;
    }

    inline int read()
    {
        int x = 0;
        char c = gc();
        for (; c < '0' || c > '9'; c = gc())
            ;
        for (; c >= '0' && c <= '9'; c = gc())
            x = (x << 3) + (x << 1) + c - '0';
        return x;
    }
    inline void _write(long long x)
    {
        if (x > 9)
            _write(x / 10);
        putchar(x % 10 + '0');
    }
    inline void write(long long x)
    {
        _write(x);
        putchar('\n');
    }
}; // namespace reader
int c[N], vis[N];
BIT tr;
struct node
{
    int l, r, id;
};
node nd[N];
bool cmp(const node &a, const node &b)
{
    return a.r == b.r ? a.l < b.l : a.r < b.r;
}
int ans[N];
int main()
{
    int n = reader::read();
    for (int i = 1; i <= n; ++i)
        c[i] = reader::read();
    int q = reader::read();
    for (int i = 1; i <= q; ++i)
        nd[i].l = reader::read(), nd[i].r = reader::read(), nd[i].id = i;
    sort(nd + 1, nd + q + 1, cmp);
    int pos = 1;
    for (int i = 1; i <= q; ++i)
    {
        while (pos <= nd[i].r)
        {
            if (!vis[c[pos]])
            {
                vis[c[pos]] = pos;
                tr.update(pos, 1, n);
            }
            else
            {
                tr.update(vis[c[pos]], -1, n);
                vis[c[pos]] = pos;
                tr.update(pos, 1, n);
            }
            ++pos;
        }
        ans[nd[i].id] = tr.sum(nd[i].l, nd[i].r, n);
    }
    for (int i = 1; i <= q; ++i)
        printf("%d\n", ans[i]);
    return 0;
}