#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e3 + 5, M = 1e3 + 5;
const ll mod = 1e9 + 7;
struct p
{
    int x, y, d;
};
p s[N];
int sum[M][M];
ll c[N][N];
ll count(int x, int y, int l, int r)
{
    if (l > r || x > y)
        return 0;
    l = max(1, l), r = min(1000, r);
    x = max(1, x), y = min(1000, y);
    return sum[y][r] - sum[y][l - 1] - sum[x - 1][r] + sum[x - 1][l - 1];
}
int main()
{
    int n, m, r;
    scanf("%d%d%d", &n, &m, &r);
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d%d%d", &s[i].x, &s[i].y, &s[i].d);
        ++sum[s[i].x][s[i].y];
    }
    for (int i = 1; i <= 1e3; ++i)
        for (int j = 1; j <= 1e3; ++j)
            sum[i][j] = sum[i][j] + sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1];
    for (int i = 0; i <= 2e3; ++i)
    {
        c[i][0] = 1;
        for (int j = 1; j <= i; ++j)
            c[i][j] = (c[i - 1][j - 1] + c[i - 1][j]) % mod;
    }
    ll ans = 0;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
        {
            ll val = 1ll * s[i].d * s[j].d % mod;
            ll num = c[n][m];
            ll cnt = n - count(s[i].x - r, s[i].x + r, s[i].y - r, s[i].y + r);
            num = (num - c[cnt][m] + mod) % mod; //有a
            cnt = n - count(s[j].x - r, s[j].x + r, s[j].y - r, s[j].y + r);
            num = (num - c[cnt][m] + mod) % mod; //有b
            cnt = n - count(s[i].x - r, s[i].x + r, s[i].y - r, s[i].y + r) -
                  count(s[j].x - r, s[j].x + r, s[j].y - r, s[j].y + r) +
                  count(max(s[i].x, s[j].x) - r, min(s[i].x, s[j].x) + r,
                        max(s[i].y, s[j].y) - r, min(s[i].y, s[j].y) + r); // 有a或b
            num = (num + c[cnt][m]) % mod;
            ans = (ans + num * val % mod) % mod;
        }
    printf("%lld\n", ans);
    return 0;
}
