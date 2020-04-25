#include <bits/stdc++.h>
using namespace std;
const int M = 1e5 + 5;
const int N = 1e2 + 5;
const int W = 4e4 + 5;
pair<int, int> q[M];
int v[N], w[N], m[N];
int dp[W];
int main()
{
    int n, t;
    int ans = 0;
    scanf("%d%d", &n, &t);
    for (int i = 1; i <= n; ++i)
        scanf("%d%d%d", &v[i], &w[i], &m[i]);
    for (int i = 1; i <= n; ++i)
    {
        if (w[i] == 0)
        {
            ans += v[i] * c[i];
            continue;
        }
        int lim = min(m[i], t / w[i]);
        for (int lef = 0; lef < w[i]; ++lef)
        {
            int head = 0, tail = 0;
            for (int k = 0; k <= (t - lef) / w[i]; ++k)
            {
                int tmp = dp[lef + k * w[i]] - k * v[i];
                while (head < tail && q[tail - 1].second <= tmp)
                    --tail;
                while (head < tail && q[head].first < k - lim)
                    ++head;
                q[tail++] = {k, tmp};
                dp[lef + k * w[i]] = q[head].second + k * v[i];
            }
        }
    }
    printf("%d\n", ans + dp[t]);
    return 0;
}