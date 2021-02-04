#include "../base.h"

const int N = 2e5 + 5;
bool multi = 1;
ll a[N];
unordered_map<ll, int> mp;
void solve()
{
    mp.clear();
    int n;
    scanf("%d", &n);
    n <<= 1;
    for (int i = 1; i <= n; ++i)
        scanf("%lld", a + i);
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; i += 2)
    {
        if (a[i] != a[i + 1])
            return void(printf("NO\n"));
        if (a[i] % 2)
            return void(printf("NO\n"));
    }
    ll lst = 0;
    for (int i = n; i >= 2; i -= 2)
    {
        if (a[i] - lst <= 0 || (a[i] - lst) % i)
            return void(printf("NO\n"));
        ll cur = (a[i] - lst) / i;
        if (mp.find(cur) != mp.end())
            return void(printf("NO\n"));
        lst += 2 * cur;
        mp[cur] = 1;
    }
    printf("YES\n");
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