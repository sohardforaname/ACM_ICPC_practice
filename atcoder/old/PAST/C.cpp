#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve()
{
    ll n, m, q;
    scanf("%lld%lld%lld", &n, &m, &q);
    if (m == 1)
        printf("%lld\n", n);
    else
    {
        for (int i = 1; i < q; ++i)
        {
            n = n * m;
            if (n > 1e9)
            {
                printf("large\n");
                return;
            }
        }
        printf("%lld\n", n);
    }
}
int main()
{
    int T = 1;
    //scanf("%d", &T);
    while (T--)
        solve();
    return 0;
}