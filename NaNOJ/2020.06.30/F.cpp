#include <bits/stdc++.h>
using namespace std;
const int N = 1e2 + 5;
char mp[N][N], cnt[N][N][2];
int xl = 1000, xr = 0, yl = 1000, yr = 0;
map<int, int> p =
    {{125, 0}, {120, 1}, {55, 2}, {87, 3}, {90, 4}, {79, 5}, {111, 6}, {81, 7}, {127, 8}, {95, 9}};
int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        scanf("%s", &mp[i][1]);
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            if (mp[i][j] == '1')
            {
                xl = min(xl, i);
                yl = min(yl, j);
                xr = max(xr, i);
                yr = max(yr, j);
                if (mp[i][j + 1] == '1')
                    ++cnt[i][j][0];
                if (mp[i + 1][j] == '1')
                    ++cnt[i][j][1];
            }
    int xm = (xl + xr) >> 1, ans = 0;
    if (cnt[xl][yl][0])
        ans += 1 << 0;
    if (cnt[xm][yl][0])
        ans += 1 << 1;
    if (cnt[xr][yl][0])
        ans += 1 << 2;
    if (cnt[xl][yl][1])
        ans += 1 << 3;
    if (cnt[xl][yr][1])
        ans += 1 << 4;
    if (cnt[xm][yl][1])
        ans += 1 << 5;
    if (cnt[xm][yr][1])
        ans += 1 << 6;
    printf("%d\n", p[ans]);
    return 0;
}