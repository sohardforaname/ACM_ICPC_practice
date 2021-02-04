#include <bits/stdc++.h>
using namespace std;
const int N = 1e2 + 5;
pair<int, int> p[N];
int dis[N][N];
void solve()
{
    int n, k;
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; ++i)
        scanf("%d%d", &p[i].first, &p[i].second);
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            dis[i][j] = abs(p[i].first - p[j].first) + abs(p[i].second - p[j].second);
    for (int i = 1; i <= n; ++i)
    {
        bool f = 1;
        for (int j = 1; j <= n; ++j)
            if (dis[i][j] > k)
            {
                f = 0;
                break;
            }
        if (f)
            return void(printf("1\n"));
    }
    return void(printf("-1\n"));
}
int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
        solve();
    return 0;
}