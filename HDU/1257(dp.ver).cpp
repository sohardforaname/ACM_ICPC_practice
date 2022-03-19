#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int a[N], dp[N];
int main()
{
    int n;
    while (~scanf("%d", &n))
    {
        for (int i = 1; i <= n; ++i)
            scanf("%d", &a[i]);
        int len = 0;
        for (int i = 1; i <= n; ++i)
        {
            if (a[i] > dp[len])
                dp[++len] = a[i];
            else
            {
                int pos = lower_bound(dp + 1, dp + len + 1, a[i]) - dp;
                dp[len] = a[i];
            }
        }
        printf("%d\n", len);
    }
    return 0;
}