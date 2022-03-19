#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
const int M = 1e6 + 5;
int a[N];
int sum[N];
int ans[M];
int check(int x, int n)
{
    int ans = 0;
    for (; x < sum[n]; x *= 2)
    {
        int pos = lower_bound(sum + 1, sum + n + 1, x) - sum;
        if (pos == n + 1)
            break;
    }
    return ans;
}
int main()
{
    int n, maxn = 0;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &a[i]), maxn = max(maxn, a[i]);
    for (int i = 1; i <= n; ++i)
        sum[i] += sum[i - 1];
    int m, a;
    scanf("%d", &m);
    for (int i = 1; i <= m; ++i)
    {
        scanf("%d", &a);
        if (maxn > a)
        {
            puts("Impossible\n");
            continue;
        }
        if (!ans[a])
            ans[a] = check(a, n);
        printf("%d\n", ans[a]);
    }
    return 0;
}