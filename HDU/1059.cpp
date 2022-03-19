#include <bits/stdc++.h>
using namespace std;
const int N = 1e1 + 5;
const int M = 2e5 + 5;
int v[N] = {0, 1, 2, 3, 4, 5, 6}, c[N];
int dp[M];
pair<int, int> q[M];
int input(int &sum)
{
    sum = 0;
    for (int i = 1; i <= 6; ++i)
        scanf("%d", &c[i]), sum += c[i] * v[i];
    return sum;
}
int main()
{
    int sum, cas = 0;
    while (input(sum))
    {
        printf("Collection #%d:\n", ++cas);
        if (sum % 2)
        {
            printf("Can't be divided.\n\n");
            continue;
        }
        memset(dp, 0, sizeof(dp));
        sum /= 2;
        for (int i = 1; i <= 6; ++i)
        {
            if (c[i] == 0)
                continue;
            int lim = min(sum / v[i], c[i]);
            for (int lef = 0; lef < v[i]; ++lef)
            {
                int head = 0, tail = 0;
                for (int k = 0; k <= (sum - lef) / v[i]; ++k)
                {
                    int tmp = dp[lef + k * v[i]] - k * v[i];
                    while (head < tail && q[tail - 1].second <= tmp)
                        --tail;
                    while (head < tail && q[head].first < k - lim)
                        ++head;
                    q[tail++] = {k, tmp};
                    dp[lef + k * v[i]] = q[head].second + k * v[i];
                }
            }
        }
        if (dp[sum] == sum)
            printf("Can be divided.\n\n");
        else
            printf("Can't be divided.\n\n");
    }
    return 0;
}