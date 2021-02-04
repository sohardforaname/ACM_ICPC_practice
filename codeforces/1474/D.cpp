#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
typedef long long ll;

bool multi = 1;
ll a[N], l[N], r[N];
void solve()
{
    int n;
    scanf("%d", &n);
    memset(l, 0, sizeof(l[0]) * (n + 2));
    memset(r, 0, sizeof(r[0]) * (n + 2));
    a[n + 1] = 0;
    for (int i = 1; i <= n; ++i)
        scanf("%lld", &a[i]);
    l[0] = a[0];
    for (int i = 1; i < n + 2; ++i)
    {
        if (l[i - 1] == -1 || l[i - 1] > a[i])
            l[i] = -1;
        else
            l[i] = a[i] - l[i - 1];
    }
    r[n + 1] = a[n + 1];
    for (int i = n; i >= 0; --i)
    {
        if (r[i + 1] == -1 || r[i + 1] > a[i])
            r[i] = -1;
        else
            r[i] = a[i] - r[i + 1];
    }
    for (int i = 0; i < n + 1; ++i)
        if (l[i] != -1 && r[i + 1] != -1 && l[i] == r[i + 1])
            return void(printf("YES\n"));
    for (int i = 1; i < n; ++i)
        if (l[i - 1] != -1 && r[i + 2] != -1 && l[i - 1] <= a[i + 1] && r[i + 2] <= a[i] && a[i + 1] - l[i - 1] == a[i] - r[i + 2])
            return void(printf("YES\n"));
    printf("NO\n");
}
int main()
{
    int t;
    if (multi)

        scanf("%d", &t);
    else
        t = 1;
    while (t--)
        solve();
    return 0;
}