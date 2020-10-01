#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
typedef long long ll;
int a[N];
void solve()
{
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &a[i]);
    sort(a + 1, a + n + 1);
    ll maxn = -1e18;
    int negn = 5;
    for (int i = 0; i <= negn; ++i)
    {
        ll tmp = 1;
        for (int j = 1; j <= i; ++j)
            tmp *= a[j];
        for (int j = 1; j <= 5 - i; ++j)
            tmp *= a[n - j + 1];
        maxn = max(maxn, tmp);
    }
    printf("%lld\n", maxn);
}
int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
        solve();
    return 0;
}