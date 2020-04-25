#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5 + 5;
ll a[N];
void solve()
{
    ll n;
    scanf("%lld", &n);
    for (int i = 2; i <= n; ++i)
        if (n % a[i] == 0)
        {
            printf("%lld\n", n / a[i]);
            return;
        }
}
int main()
{
    for (int i = 1; i <= 50; ++i)
        a[i] = (1ll << i) - 1;
    int T;
    scanf("%d", &T);
    while (T--)
        solve();
    return 0;
}
