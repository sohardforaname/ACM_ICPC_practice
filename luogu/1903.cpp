#include <bits/stdc++.h>
using namespace std;

const int N = 1.5e5 + 5;
const int M = 1.5e5 + 5;
int col[N], blk[M];
int buc[N * 7];
struct qnode
{
    int l, r, tm, id;
    bool operator<(const qnode &a) const
    {
        if (blk[l] != blk[a.l])
            return blk[l] < blk[a.l];
        if (blk[r] != blk[a.r])
            return blk[r] < blk[a.r];
        return tm < a.tm;
    }
};
qnode q[N];
struct cnode
{
    int color, pos;
};
cnode c[N];
int ans[N], cur;
int main()
{
    char op[2];
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &col[i]);
    int cntq = 0, cntc = 0;
    for (int i = 1; i <= m; ++i)
    {
        scanf("%s", op);
        if (op[0] == 'Q')
        {
            ++cntq;
            scanf("%d%d", &q[cntq].l, &q[cntq].r);
            q[cntq].tm = cntc;
            q[cntq].id = cntq;
        }
        else if (op[0] == 'R')
        {
            ++cntc;
            scanf("%d%d", &c[cntc].pos, &c[cntc].color);
        }
    }
    int len = pow(n, 2.0 / 3.0), t = ceil(n * 1.0 / len);
    for (int i = 1; i <= n; ++i)
        blk[i] = (i - 1) / len + 1;
    sort(q + 1, q + cntq + 1);
    int l = 1, r = 0, tm = 0;
    cur = 0;
    for (int i = 1; i <= cntq; ++i)
    {
        int ql = q[i].l, qr = q[i].r, qt = q[i].tm;
        while (l < ql)
            cur -= !(--buc[col[l++]]);
        while (l > ql)
            cur += !(buc[col[--l]]++);
        while (r < qr)
            cur += !(buc[col[++r]]++);
        while (r > qr)
            cur -= !(--buc[col[r--]]);
        while (tm < qt)
        {
            ++tm;
            if (q[i].l <= c[tm].pos && c[tm].pos <= q[i].r)
            {
                int v = col[c[tm].pos];
                cur -= !(--buc[v]) - !(buc[c[tm].color]++);
            }
            swap(col[c[tm].pos], c[tm].color);
        }
        while (tm > qt)
        {
            if (q[i].l <= c[tm].pos && c[tm].pos <= q[i].r)
            {
                int v = col[c[tm].pos];
                cur -= !(--buc[v]) - !(buc[c[tm].color]++);
            }
            swap(col[c[tm].pos], c[tm].color);
            --tm;
        }
        ans[q[i].id] = cur;
    }
    for (int i = 1; i <= cntq; ++i)
        printf("%d\n", ans[i]);
    return 0;
}