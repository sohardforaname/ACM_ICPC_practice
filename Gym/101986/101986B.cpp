#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e1 + 5;
int n;
pair<int, int> d[N][N];
map<pair<int, int>, int> mp;
int pos[N][2];
int maxn;
bool vis[N];
void dfs(int pos)
{
    if (pos == n + 1)
    {
        int cnt = 0;
        for (auto i : mp)
            cnt += i.second * (i.second - 1) / 2;
        maxn = max(maxn, cnt);
    }
    if (!vis[pos])
        for (int i = pos + 1; i <= n; ++i)
        {
            if (!vis[i])
            {
                vis[i] = 1;
                ++mp[d[pos][i]];
                dfs(pos + 1);
                --mp[d[pos][i]];
                vis[i] = 0;
            }
        }
    else
        dfs(pos + 1);
}
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        scanf("%d%d", &pos[i][0], &pos[i][1]);
    for (int i = 1; i <= n; ++i)
        for (int j = i + 1; j <= n; ++j)
        {
            int dx = pos[i][0] - pos[j][0];
            int dy = pos[i][1] - pos[j][1];
            if (dx < 0)
                dx = -dx, dy = -dy;
            else if (dx == 0)
                dy = abs(dy);
            int gcd = __gcd(dx, dy);
            d[i][j] = d[j][i] = {dx / gcd, dy / gcd};
        }
    dfs(1);
    printf("%d\n", maxn);
    system("pause");
    return 0;
}
/*
16
327 449
-509 761
-553 515
360 948
147 877
-694 468
241 320
463 -753
-206 -991
473 -738
-156 -916
-215 54
-112 -476
-452 780
-18 -335
-146 77
*/
