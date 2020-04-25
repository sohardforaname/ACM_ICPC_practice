#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e4;
const int M = 1e7;
int t[N], w[N];
ll dp[M];
int main()
{
    int n, m;
    scanf("%d%d", &m, &n);
    for (int i = 1; i <= n; ++i)
        scanf("%d%d", &t[i], &w[i]);
    for (int i = 1; i <= n; ++i)
        for (int j = t[i]; j <= m; ++j)
            dp[j] = max(dp[j], dp[j - t[i]] + w[i]);
    printf("%lld\n", dp[m]);
    return 0;
}