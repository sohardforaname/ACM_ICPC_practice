#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 5;
typedef long long ll;
int dis[N][N];

int main()
{
    memset(dis, 0x3f, sizeof(dis));
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i)
        dis[i][i] = 0;
    for (int i = 1; i <= m; ++i)
    {
        int u, v, w;
        scanf("%d%d%d", &u, &v, &w);
        dis[u][v] = min(dis[u][v], w);
    }
    for (int k = 1; k <= n; ++k)
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= n; ++j)
                dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
    int ans = 0;
    for (int i = 2; i <= n; ++i)
        ans += dis[1][i] + dis[i][1];
    printf("%d\n", ans);
    return 0;
}