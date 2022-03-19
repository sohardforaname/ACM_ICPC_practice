#include "../base.h"

bool multi = 0;
const int N = 5e5 + 5;
int a[N], l[N], r[N], cnt[N];
int dp[N];

void solve()
{
    int n;
    io(n);
    io(IO::make(a, 1, n + 1));
    for (int i = 1; i <= n; ++i) {
        if (!l[a[i]])
            l[a[i]] = i;
        r[a[i]] = max(r[a[i]], i);
    }
    for (int i = n; i; --i) {
        ++cnt[a[i]];
        if (i == l[a[i]])
            dp[i] = max({ dp[i + 1], cnt[a[i]] + dp[r[a[i]] + 1] });
        else
            dp[i] = max(dp[i + 1], cnt[a[i]]);
    }
    io(n - dp[1], '\n');
}

MAIN_FUNC