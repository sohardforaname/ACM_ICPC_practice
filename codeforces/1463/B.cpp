#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 55;
int a[N];
int ans1[N], ans2[N];
void solve()
{
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &a[i]);
    for (int i = 1; i <= n; ++i)
    {
        if (i % 2)
            ans1[i] = a[i], ans2[i] = 1;
        else
            ans1[i] = 1, ans2[i] = a[i];
    }
    ll sum1 = 0, sum2 = 0, sum3 = 0;
    for (int i = 1; i <= n; ++i)
    {
        sum1 += a[i];
        sum2 += abs(a[i] - ans1[i]);
        sum3 += abs(a[i] - ans2[i]);
    }
    if (sum2 * 2 <= sum1)
        for (int i = 1; i <= n; ++i)
            printf("%d%c", ans1[i], " \n"[i == n]);
    else
        for (int i = 1; i <= n; ++i)
            printf("%d%c", ans2[i], " \n"[i == n]);
}
int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
        solve();
    return 0;
}