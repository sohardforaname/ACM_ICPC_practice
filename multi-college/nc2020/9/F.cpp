#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
pair<int, int> p[N];
int vis[N];
int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    int cnt = 0;
    for (int i = 1; i <= n; ++i)
    {
        int k;
        scanf("%d", &k);
        for (int j = 1; j <= k; ++j)
        {
            scanf("%d", &p[++cnt].first);
            p[cnt].second = i;
        }
    }
    sort(p + 1, p + cnt + 1);
    int ans = 0x3f3f3f3f;
    int l = 1, r = 1, ncnt = 0;
    while (l <= cnt && r <= cnt)
    {
        while (r <= cnt && ncnt <= n)
        {
            if (!vis[p[r].second])
                ++vis[p[r].second], ++ncnt;
            ++r;
        }
        while (l <= cnt && ncnt >= n)
        {
            if (vis[p[l].second] == 1)
                break;
            ++l;
        }
        for (int i = 1; i <= r - l - m + 1; ++i)
            ans = min(ans, p[l + i + m - 2].first - p[l + i - 1].first);
        while (ncnt >= n)
        {
            ;
        }
    }
}