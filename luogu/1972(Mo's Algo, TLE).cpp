#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5, M = 1e3 + 5;
typedef long long ll;
int num[N], c[N];
int bg[M], ed[M];
int cnt[N];

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

struct node
{
    int l, r, id, blk;
};
bool cmp(const node &a, const node &b)
{
    return a.blk == b.blk ? (a.blk & 1 ? a.r < b.r : a.r > b.r) : a.blk < a.blk;
}
node nd[N];
int ans[N];
int main()
{
    int n;
    n = reader::read();
    for (int i = 1; i <= n; ++i)
        c[i] = reader::read();
    int q;
    q = reader::read();
    int t = ceil(sqrt(q)), len = q / t;
    for (int i = 1; i <= q; ++i)
    {
        nd[i].l = reader::read();
        nd[i].r = reader::read();
        nd[i].id = i;
        nd[i].blk = (i - 1) / len + 1;
    }
    sort(nd + 1, nd + q + 1, cmp);
    int now = 0;
    for (int l = 1, r = 0, i = 1; i <= q; ++i)
    {
        while (l < nd[i].l)
            now -= !--cnt[c[l++]];
        while (l > nd[i].l)
            now += !cnt[c[--l]]++;
        while (r < nd[i].r)
            now += !cnt[c[++r]]++;
        while (r > nd[i].r)
            now -= !--cnt[c[r--]];
        ans[nd[i].id] = now;
    }
    for (int i = 1; i <= q; ++i)
        reader::write(ans[i]);
    return 0;
}