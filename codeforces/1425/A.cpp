#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5 + 5;
void solve()
{
    ll n;
    scanf("%lld", &n);
    ll ans = 0;
    bool f = 1;
    while (n)
    {
        if (n % 2)
        {
            if (f)
                ans += 1;
            n -= 1;
        }
        else if (n % 4 || n == 4)
        {
            if (f)
                ans += n / 2;
            n /= 2;
        }
        else
        {
            if (f)
                ans += 1;
            n -= 1;
        }
        f = !f;
    }
    printf("%lld\n", ans);
}
int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
        solve();
    return 0;
}