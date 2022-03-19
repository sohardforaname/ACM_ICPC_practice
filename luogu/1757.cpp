#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 5;
int a[N], b[N], c[N];
int dp[N];
vector<int> G[N];
int main()
{
    int n, m, g = 0;
    scanf("%d%d", &m, &n);
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d%d%d", &a[i], &b[i], &c[i]);
        g = max(g, c[i]);
        G[c[i]].push_back(i);
    }
    for (int i = 1; i <= g; ++i)
        for (int j = m; j >= 0; --j)
            for (int k = 0; k < G[i].size(); ++k)
                if (j >= a[G[i][k]])
                    dp[j] = max(dp[j], dp[j - a[G[i][k]]] + b[G[i][k]]);
    printf("%d\n", dp[m]);
    return 0;
}