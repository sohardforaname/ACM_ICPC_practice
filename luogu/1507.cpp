#include <bits/stdc++.h>
using namespace std;
const int N = 50;
const int M = 4e2 + 5;
int v[N], m[N], c[N];
int dp[M][M];
int main()
{
    int n;
    int a, b;
    scanf("%d%d%d", &a, &b, &n);
    for (int i = 1; i <= n; ++i)
        scanf("%d%d%d", &v[i], &m[i], &c[i]);
    for (int i = 1; i <= n; ++i)
        for (int j = a; j >= v[i]; --j)
            for (int k = b; k >= m[i]; --k)
                dp[j][k] = max(dp[j][k], dp[j - v[i]][k - m[i]] + c[i]);
    printf("%d\n", dp[a][b]);
    return 0;
}