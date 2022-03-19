#include <bits/stdc++.h>
using namespace std;
const int N = 1.2e3 + 5;
int fa[N], sz[N];
int dp[N][N];
int find(int x)
{
    return fa[x] == x ? x : fa[x] = find(fa[x]);
}
void join(int x, int y)
{
    int fx = find(x), fy = find(y);
    if (fx ^ fy)
        fa[fx] = fy, sz[fy] += sz[fx];
}
char op[5];
int vis[N], tot;
int a[N], b[N];
int main()
{
    int n, x, y;
    while (~scanf("%d%d%d", &n, &x, &y) && n + x + y)
    {
        tot = 0;
        for (int i = 1; i <= x + y; ++i)
        {
            fa[i] = i;
            fa[i + x + y] = i + x + y;
            sz[i] = 1;
            sz[i + x + y] = 0;
            vis[i] = 0;
            vis[i + x + y] = 0;
        }
        for (int i = 1; i <= n; ++i)
        {
            int u, v;
            scanf("%d%d%s", &u, &v, op);
            if (op[0] == 'y')
                join(u, v), join(u + x + y, v + x + y);
            else
                join(u, v + x + y), join(u + x + y, v);
        }
        for (int i = 1; i <= x + y; ++i)
        {
            int fi = find(i);
            if (fi != i)
                continue;
            vis[fi + x + y] = vis[fi] = ++tot;
            a[tot] = sz[fi], b[tot] = sz[fi + x + y];
        }
        memset(dp, 0, sizeof(dp));
        dp[0][0] = 1;
        for (int i = 1; i <= tot; ++i)
            for (int j = min(a[i], b[i]); j <= x; ++j)
            {
                if (j >= a[i])
                    dp[i][j] += dp[i - 1][j - a[i]];
                if (j >= b[i])
                    dp[i][j] += dp[i - 1][j - b[i]];
            }
        if (dp[tot][x] != 1)
        {
            puts("no");
            continue;
        }
        int cur = x;
        for (int i = tot; i; --i)
        {
            if (dp[i - 1][cur - a[i]])
                cur -= a[i], a[i] = -1;
            else if (dp[i - 1][cur - b[i]])
                cur -= b[i], a[i] = -2;
        }
        for (int i = 1; i <= x + y; ++i)
        {
            int fi = find(i);
            if (vis[fi])
            {
                if (fi <= x + y && a[vis[fi]] == -1)
                    printf("%d\n", i);
                else if (fi > x + y && a[vis[fi]] == -2)
                    printf("%d\n", i);
            }
        }
        puts("end");
    }
    return 0;
}