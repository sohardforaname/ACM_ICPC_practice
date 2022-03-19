#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 5;
int q[N], sum[N];
char s[N], t[N];
int dp[N];
int main()
{
    int n, k;
    scanf("%d%d", &n, &k);
    scanf("%s%s", s + 1, t + 1);
    for (int i = 1; i <= n; ++i)
        sum[i] = sum[i - 1] + (t[i] != t[i - 1]);
    int head = 1, tail = 1;
    q[1] = 0; //初始状态，必备
    for (int i = 1; i <= n; ++i)
    {
        if (s[i] == t[i])
            dp[i] = dp[i - 1];
        else
            dp[i] = dp[q[head]] + (sum[i] - sum[q[head] + 1] + 1) / 2 + 1;
        while (head <= tail && dp[i] * 2 - sum[i + 1] <= dp[q[tail]] * 2 - sum[q[tail] + 1])
            --tail;
        while (head <= tail && i - q[head] >= k)
            ++head;
        q[++tail] = i;
    }
    printf("%d\n", dp[n]);
    return 0;
}