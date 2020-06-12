#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 5;
char mp[N][N];
void solve()
{
    int n, m, x, y;
    scanf("%d%d%d%d", &n, &m, &x, &y);
    for (int i = 1; i <= n; ++i)
        scanf("%s", &mp[i][1]);
    bool f = 0;
    if (2 * x > y)
        f = 1;
    int ans = 0;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m;)
        {
            if (mp[i][j] == '*')
            {
                ++j;
                continue;
            }
            if (!f || j == m || mp[i][j] != mp[i][j + 1])
                ans += x, ++j;
            else
                ans += y, j += 2;
        }
    printf("%d\n", ans);
}
int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
        solve();
    return 0;
}