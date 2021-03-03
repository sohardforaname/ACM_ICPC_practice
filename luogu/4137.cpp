#include "../base.h"

bool multi = 0;
const int N = 2e5 + 5, M = 500;
int a[N], cnt[N];
int blk[N], nums[M], bg[M], ed[M];

void add(int v)
{
    if (!(cnt[v]++))
        ++nums[blk[v]];
}
void del(int v)
{
    if (!(--cnt[v]))
        --nums[blk[v]];
}
int query()
{
    for (int i = 1; i < M; ++i) {
        if (nums[i] != ed[i] - bg[i] + 1) {
            for (int j = bg[i]; j <= ed[i]; ++j) {
                if (!cnt[j]) {
                    return j;
                }
            }
        }
    }
}
struct que {
    int l, r, id;
} qu[N];
int ans[N];
bool cmpa(const que& a, const que& b)
{
    return a.l < b.l;
};
bool cmpb(const que& a, const que& b)
{
    return a.r < b.r;
}
void solve()
{
    int n, q;
    io(n, q);
    int t = sqrt(n), len = n / t;
    for (int i = 0; i <= n; ++i) {
        blk[i] = i / len + 1;
    }
    for (int i = 1; i <= t; ++i) {
        bg[i] = (i - 1) * len, ed[i] = i * len - 1;
    }
    if (ed[t] < n)
        bg[t + 1] = ed[t] + 1, ed[++t] = n;
    io(IO::make(a, 1, n + 1));
    for (int i = 1; i <= q; ++i) {
        io(qu[i].l, qu[i].r);
        qu[i].id = i;
    }
    sort(qu + 1, qu + q + 1, cmpa);
    for (int i = 1; i <= t; ++i) {
        sort(qu + bg[i], qu + ed[i] + 1, cmpb);
    }
    int l = qu[1].l, r = qu[1].r;
    for (int i = l; i <= r; ++i)
        add(a[i]);
    ans[qu[1].id] = query();
    for (int i = 2; i <= q; ++i) {
        while (l < qu[i].l)
            del(a[l++]);
        while (r > qu[i].r)
            del(a[r--]);
        while (l > qu[i].l)
            add(a[--l]);
        while (r < qu[i].r)
            add(a[++r]);
        ans[qu[i].id] = query();
    }
    io(ans, 1, q + 1, '\n');
}

MAIN_FUNC