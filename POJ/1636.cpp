#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

const int N = 4e2 + 5;

int fa[N];
pair<int, int> p[N];
int dp[N][N];

int find(int x)
{
    return fa[x] == x ? x : fa[x] = find(fa[x]);
}

void join(int x, int y)
{
    int fx = find(x), fy = find(y);
    if (fx ^ fy)
        fa[fx] = fy;
}
int cnt1[N], cnt2[N];
void solve()
{
    int m, r;
    scanf("%d%d", &m, &r);
    for (int i = 1; i <= m * 2; ++i)
        fa[i] = i;
    for (int i = 1; i <= r; ++i)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        join(x, y + m);
    }
    memset(cnt1, 0, sizeof(cnt1));
    memset(cnt2, 0, sizeof(cnt2));
    for (int i = 1; i <= m; ++i)
        ++cnt1[find(i)];
    for (int i = m + 1; i <= m * 2; ++i)
        ++cnt2[find(i)];
    memset(dp, 0, sizeof(dp));
    dp[0][0] = 1;
    int n = 0;
    for (int i = 1; i <= 2 * m; ++i)
        if (cnt1[i] || cnt2[i])
            p[++n] = make_pair(cnt1[i], cnt2[i]);
    for (int i = 1; i <= n; ++i)
        for (int j = m >> 1; j >= p[i].first; --j)
            for (int k = m >> 1; k >= p[i].second; --k)
                dp[j][k] |= dp[j - p[i].first][k - p[i].second];
    int ans = m >> 1;
    while (!dp[ans][ans])
        --ans;
    printf("%d\n", ans);
}
int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
        solve();
    return 0;
}