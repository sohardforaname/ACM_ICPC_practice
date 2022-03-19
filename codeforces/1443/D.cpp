#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 3e4 + 5;
ll a[N], minn[N];
void solve()
{
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        scanf("%lld", &a[i]);
    minn[0] = 0x3f3f3f3f;
    for (int i = 1; i <= n; ++i)
        minn[i] = min(minn[i - 1], a[i]);
    ll d = 0, rmin = 0x3f3f3f3f;
    for (int i = n; i; --i)
    {
        if (a[i] - d <= rmin)
            rmin = a[i] - d;
        else if (a[i] - rmin - d <= minn[i - 1] - d)
            d += a[i] - rmin - d;
        else
            return void(printf("NO\n"));
    }
    printf("YES\n");
}
int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
        solve();
    return 0;
}