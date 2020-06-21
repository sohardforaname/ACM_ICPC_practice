#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int a[N];
void solve()
{
    int n, sum = 0, x;
    scanf("%d%d", &n, &x);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &a[i]), sum += a[i];
    if (sum % x)
    {
        printf("%d\n", n);
        return;
    }
    int tmp = sum, i, ans = -1;
    for (i = 1; i <= n && tmp % x == 0; ++i)
        tmp -= a[i];
    ans = max(ans, n - i + 1);
    tmp = sum;
    for (i = n; i && tmp % x == 0; --i)
        tmp -= a[i];
    ans = max(ans, i);
    printf("%d\n", ans ? ans : ans - 1);
}
int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
        solve();
    return 0;
}