#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
typedef long long ll;
void solve()
{
    int n;
    scanf("%d", &n);
    if (n % 4)
    {
        printf("NO\n");
        return;
    }
    printf("YES\n");
    long long tot = 0;
    int cur = 2;
    for (int i = 1; i <= n / 2; ++i)
        printf("%d ", cur), tot += cur, cur += 2;
    cur = 1;
    for (int i = 1; i < n / 2; ++i)
        printf("%d ", cur), tot -= cur, cur += 2;
    printf("%lld\n", tot);
}
int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
        solve();
    return 0;
}