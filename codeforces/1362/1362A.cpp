#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int get(ll a)
{
    while (a % 2 == 0)
        a /= 2;
    return a;
}
void solve()
{
    ll a, b;
    scanf("%lld%lld", &a, &b);
    if (a > b)
        swap(a, b);
    if (get(a) != get(b))
    {
        printf("-1\n");
        return;
    }
    b /= a;
    int ans = 0;
    while (b && b % 8 == 0)
        ++ans, b /= 8;
    if (b > 1)
        ++ans;
    printf("%d\n", ans);
}
int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
        solve();
    return 0;
}