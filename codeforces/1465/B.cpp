#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve()
{
    ll n;
    scanf("%lld", &n);
    while (1)
    {
        ll num = n;
        bool f = 0;
        while (num)
        {
            if ((num % 10) && (n % (num % 10)))
            {
                f = 1;
                break;
            }
            num /= 10;
        }
        if (!f)
            return void(printf("%lld\n", n));
        ++n;
    }
}
int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
        solve();
    return 0;
}