#include <bits/stdc++.h>
using namespace std;
const int N = 4e3 + 5;
int dp[N];
int a[N], s[N], top;
void solve()
{
    int n;
    top = 0;
    scanf("%d", &n);
    for (int i = 1; i <= n * 2; ++i)
        scanf("%d", &a[i]);
    int maxn = a[1];
    for (int i = 1; i <= n * 2;)
    {
        int nxt = i;
        while (nxt <= n * 2 && a[nxt] <= maxn)
            ++nxt;
        maxn = a[nxt];
        s[++top] = nxt - i;
        i = nxt;
    }
    memset(dp, 0, sizeof(dp));
    for (int i = 1; i <= top; ++i)
        for (int j = n; j >= s[i]; --j)
            dp[j] = max(dp[j], dp[j - s[i]] + s[i]);
    if (dp[n] == n)
        printf("YES\n");
    else
        printf("NO\n");
}
int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
        solve();
    return 0;
}