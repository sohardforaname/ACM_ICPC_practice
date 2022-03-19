#include <bits/stdc++.h>
using namespace std;
const int N = 1e4 + 5;
const int M = 1e3 + 5;
int t[N], c[N], p[N];
int dp[M];
pair<int, int> q[M], ts, tt;
int main()
{
    int n;
    scanf("%d:%d", &ts.first, &ts.second);
    scanf("%d:%d", &tt.first, &tt.second);
    scanf("%d", &n);
    int sum = (tt.first - ts.first) * 60 + tt.second - ts.second;
    for (int i = 1; i <= n; ++i)
        scanf("%d%d%d", &t[i], &c[i], &p[i]);
    for (int i = 1; i <= n; ++i)
    {
        if (p[i] == 0)
            for (int j = t[i]; j <= sum; ++j)
                dp[j] = max(dp[j], dp[j - t[i]] + c[i]);
        else if (p[i] == 1)
            for (int j = sum; j >= t[i]; --j)
                dp[j] = max(dp[j], dp[j - t[i]] + c[i]);
        else
        {
            int lim = min(sum / t[i], p[i]);
            for (int lef = 0; lef < t[i]; ++lef)
            {
                int head = 0, tail = 0;
                for (int k = 0; k <= (sum - lef) / t[i]; ++k)
                {
                    int tmp = dp[lef + k * t[i]] - k * c[i];
                    while (head < tail && q[tail - 1].second <= tmp)
                        --tail;
                    while (head < tail && q[head].first < k - lim)
                        ++head;
                    q[tail++] = {k, tmp};
                    dp[lef + k * t[i]] = q[head].second + k * c[i];
                }
            }
        }
    }
    printf("%d\n", dp[sum]);
    return 0;
}
