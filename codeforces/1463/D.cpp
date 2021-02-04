#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 4e5 + 5;
int a[N];
void solve()
{
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &a[i]);
    a[n + 1] = n * 2 + 1;
    int ans = n + 1, sum = 0;
    for (int i = 1; i <= n; ++i)
    {
        sum += a[i] - a[i - 1] - 1;
        if (sum == 0)
            --ans;
        else
            --sum;
    }
    sum = 0;
    for (int i = n; i; --i)
    {
        sum += a[i + 1] - a[i] - 1;
        if (sum == 0)
            --ans;
        else
            --sum;
    }
    printf("%d\n", ans);
}
int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
        solve();
    return 0;
}