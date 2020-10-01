#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5, M = 4e2 + 5;
int a[N];
int bcnt[M][N], cnt[M][M];
int bg[M], ed[M], blk[N];
int num[N];
stack<int> s;
int main()
{
    int n, c, m;
    scanf("%d%d%d", &n, &c, &m);
    int t = sqrt(n), len = n / t;
    for (int i = 1; i <= n; ++i)
        scanf("%d", &a[i]), blk[i] = (i - 1) / len + 1;
    for (int i = 1; i <= t; ++i)
        bg[i] = (i - 1) * len + 1, ed[i] = i * len;
    if (ed[t] < n)
        bg[t + 1] = ed[t] + 1, ed[++t] = n;
    for (int i = 1; i <= t; ++i)
    {
        int cur = 0;
        for (int j = bg[i]; j <= n; ++j)
        {
            ++bcnt[i][a[j]];
            if (bcnt[i][a[j]] > 1 && bcnt[i][a[j]] & 1)
                --cur;
            else if ((bcnt[i][a[j]] & 1) == 0)
                ++cur;
            if (blk[j] != blk[j + 1])
                cnt[i][blk[j]] = cur;
        }
    }
    int ans = 0;
    for (int i = 1; i <= m; ++i)
    {
        int l, r;
        scanf("%d%d", &l, &r);
        l = (l + ans) % n + 1, r = (r + ans) % n + 1;
        if (l > r)
            swap(l, r);
        int x, y;
        for (x = 1; x <= t; ++x)
            if (l <= ed[x])
                break;
        for (y = t; y; --y)
            if (r >= bg[y])
                break;
        int L, R;
        if (x + 1 <= y - 1)
            L = x + 1, R = y - 1;
        else
            L = 1, R = 0;
        ans = cnt[L][R];
        if (x == y)
        {
            for (int j = l; j <= r; ++j)
                ++num[a[j]], s.push(a[j]);
            while (s.size())
            {
                int tp = s.top();
                if (num[tp])
                {
                    ans += !(num[tp] & 1);
                    num[tp] = 0;
                }
                s.pop();
            }
        }
        else
        {
            for (int j = l; j <= ed[x]; ++j)
                ++num[a[j]], s.push(a[j]);
            for (int j = bg[y]; j <= r; ++j)
                ++num[a[j]], s.push(a[j]);
            while (s.size())
            {
                int tp = s.top();
                if (num[tp])
                {
                    int tmp = bcnt[L][tp] - bcnt[R + 1][tp];
                    if (tmp > 0 && tmp & 1 && num[tp] & 1)
                        ++ans;
                    else if (tmp > 0 && !(tmp & 1) && num[tp] & 1)
                        --ans;
                    else if (tmp == 0 && (num[tp] & 1) == 0)
                        ++ans;
                    num[tp] = 0;
                }
                s.pop();
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}