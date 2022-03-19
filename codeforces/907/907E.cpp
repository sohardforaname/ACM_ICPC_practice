#include <bits/stdc++.h>
using namespace std;
const int N = (1 << 22) + 4;
int a[30];
int dp[N]; //到达1表示的二进制所有1位置的人相互认识需要多少步
int fa[N]; //某状态是由哪个状态得到
int to[N]; //经由某个人得到这个状态
void find(int x, int p)
{
    if (fa[x])
        find(fa[x], p + 1);
    printf("%d%c", to[x], " \n"[!p]);
}
int main()
{
    memset(dp, 0x3f, sizeof(dp));
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i)
        a[i] |= 1 << (i - 1);
    for (int i = 1; i <= m; ++i)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        a[u] |= 1 << (v - 1);
        a[v] |= 1 << (u - 1);
    }
    if (m == n * (n - 1) / 2)
        return printf("0\n"), 0;
    for (int i = 1; i <= n; ++i)
    {
        dp[a[i]] = 1;
        to[a[i]] = i;
    }
    for (int i = 0; i < 1 << n; ++i)
    {
        if (dp[i] == 0x3f3f3f3f)
            continue;
        for (int j = 1; j <= n; ++j)
            if (i & (1 << (j - 1)) && dp[i | a[j]] > dp[i] + 1)
            {
                dp[i | a[j]] = dp[i] + 1;
                to[i | a[j]] = j;
                fa[i | a[j]] = i;
            }
    }
    printf("%d\n", dp[(1 << n) - 1]);
    find((1 << n) - 1, 0);
    return 0;
}