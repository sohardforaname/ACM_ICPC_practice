#include <bits/stdc++.h>
using namespace std;
const int N = 5e3 + 5;
const int M = 5e4 + 5;
int v[N];
int dp[M];
int main()
{
    int n, m;
    scanf("%d%d", &m, &n);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &v[i]);
    for (int i = 1; i <= n; ++i)
        for (int j = m; j >= v[i]; --j)
            dp[j] = max(dp[j], dp[j - v[i]] + v[i]);
    printf("%d\n", dp[m]);
    return 0;
}