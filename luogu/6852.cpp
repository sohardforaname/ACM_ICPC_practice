#include "../base.h"

bool multi = 0;
const int N = 5e5 + 5;
struct intv {
    int l, r;
};
intv a[N], b[N];
int st[N], top, ans[N];
int d[N];

void solve()
{
    int n, q;
    io(n, q);
    for (int i = 0; i <= n; ++i) {
        a[i].l = 0;
        a[i].r = n;
        b[i].l = n + 1;
        b[i].r = -1;
    }
    for (int i = 1; i <= q; ++i) {
        int l, r, v;
        //[l,r]中不存在v，存在[0, v-1]；
        //a[i]是i存在的区间[l,r]，b[i]是i不存在时的区间[l,r]
        io(l, r, v);
        if (v) {
            a[v - 1].l = max(a[v - 1].l, l);
            a[v - 1].r = min(a[v - 1].r, r);
            b[v].l = min(b[v].l, l);
            b[v].r = max(b[v].r, r);
            if (a[v - 1].l > a[v - 1].r) {
                printf("-1\n");
                return;
            }
        } else {
            ++d[l];
            --d[r + 1];
        }
    }
    for (int i = n - 1; ~i; --i) {
        a[i].l = max(a[i + 1].l, a[i].l);
        a[i].r = min(a[i + 1].r, a[i].r);
        if (a[i].l > a[i].r) {
            printf("-1\n");
            return;
        }
    }
    bool f = !d[0];
    for (int i = 1; i <= n; ++i) {
        d[i] += d[i - 1];
        if (!d[i])
            f = 1;
    }
    if (!f) {
        printf("-1\n");
        return;
    }

    for (int i = a[0].l; i <= a[0].r; ++i) {
        if (!d[i]) {
            st[++top] = i;
        }
    }
    if (!top) {
        printf("-1\n");
        return;
    }
    ans[st[top--]] = 0;
    for (int i = a[0].l; i <= a[0].r; ++i) {
        if (d[i]) {
            st[++top] = i;
        }
    }
    for (int i = 1; i <= n; ++i) {
        if (b[i].l <= a[i].l && a[i].r <= b[i].r) {
            printf("-1\n");
            return;
        }
        for (int j = a[i].l; j < a[i - 1].l; ++j) {
            if (j < b[i].l || j > b[i].r)
                st[++top] = j;
        }
        for (int j = a[i].r; j > a[i - 1].r; --j) {
            if (j < b[i].l || j > b[i].r)
                st[++top] = j;
        }
        if (!top) {
            printf("-1\n");
            return;
        }
        ans[st[top--]] = i;
        for (int j = a[i].l; j < a[i - 1].l; ++j) {
            if (j >= b[i].l && j <= b[i].r)
                st[++top] = j;
        }
        for (int j = a[i].r; j > a[i - 1].r; --j) {
            if (j >= b[i].l && j <= b[i].r)
                st[++top] = j;
        }
    }
    for (int i = 0; i <= n; ++i)
        printf("%d%c", ans[i], " \n"[i == n]);
}

MAIN_FUNC