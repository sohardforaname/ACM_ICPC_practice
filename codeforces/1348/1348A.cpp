#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve()
{
    int n;
    scanf("%d", &n);
    printf("%lld\n", (1ll << n / 2 + 1) - 2);
}
int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
        solve();
    return 0;
}