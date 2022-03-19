#include <bits/stdc++.h>
using namespace std;
const int N = 4e4 + 5, M = 4e1 + 5;
int cnt[M][M][N], d[M][M], f[M][M];
int a[N], b[N], n, q, t;
int bg[M], ed[M];
int ans, num, L, R;
void upd(int i)
{
    ++cnt[L][R][a[i]];
    if (cnt[L][R][a[i]] > ans || cnt[L][R][a[i]] == ans && a[i] < num)
        ans = cnt[L][R][a[i]], num = a[i];
}
int main()
{
    scanf("%d%d", &n, &q);
    t = pow(n * 1.0, 1.0 / 3);
    int len = n / t;
    for (int i = 1; i <= t; ++i)
        bg[i] = (i - 1) * len + 1, ed[i] = i * len;
    if (ed[t] < n)
        bg[t + 1] = ed[t] + 1, ed[++t] = n;
    for (int i = 1; i <= n; ++i)
        scanf("%d", &a[i]);
    memcpy(b, a, sizeof(a));
    sort(b + 1, b + n + 1);
    int top = unique(b + 1, b + n + 1) - b - 1;
    for (int i = 1; i <= n; ++i)
        a[i] = lower_bound(b + 1, b + top + 1, a[i]) - b;
    for (int i = 1; i <= t; ++i)
        for (int j = i; j <= t; ++j)
        {
            for (int k = bg[i]; k <= ed[j]; ++k)
                ++cnt[i][j][a[k]];
            for (int k = 1; k <= top; ++k)
                if (cnt[i][j][k] > f[i][j] || cnt[i][j][k] == f[i][j] && k < d[i][j])
                    f[i][j] = cnt[i][j][k], d[i][j] = k;
        }
    int pre = 0;
    for (int tt = 1; tt <= q; ++tt)
    {
        int l, r;
        scanf("%d%d", &l, &r);
        l = (l + pre - 1) % n + 1, r = (r + pre - 1) % n + 1;
        if (l > r)
            swap(l, r);
        int x = 0, y = 0;
        for (int i = 1; i <= t; ++i)
            if (l <= ed[i])
            {
                x = i;
                break;
            }
        for (int i = t; i; --i)
            if (r >= bg[i])
            {
                y = i;
                break;
            }
        if (x + 1 <= y - 1)
            L = x + 1, R = y - 1;
        else
            L = R = 0;
        ans = f[L][R], num = d[L][R];
        if (x == y)
        {
            for (int i = l; i <= r; ++i)
                upd(i);
            for (int i = l; i <= r; ++i)
                --cnt[L][R][a[i]];
        }
        else
        {
            for (int i = l; i <= ed[x]; ++i)
                upd(i);
            for (int i = bg[y]; i <= r; ++i)
                upd(i);
            for (int i = l; i <= ed[x]; ++i)
                --cnt[L][R][a[i]];
            for (int i = bg[y]; i <= r; ++i)
                --cnt[L][R][a[i]];
        }
        printf("%d\n", b[num]);
        pre = b[num];
    }
    return 0;
}