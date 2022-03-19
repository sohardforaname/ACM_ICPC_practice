#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
typedef long long ll;
void solve()
{
    int a[3], n;
    scanf("%d%d%d%d", &n, &a[0], &a[1], &a[2]);
    sort(a, a + 3);
    int ans = n / (a[0] + a[1] + a[2]);
    n -= ans * (a[0] + a[1] + a[2]);
    ans *= 3;
    if (n >= a[0] + a[1])
        ans += 2;
    else if (n >= a[0])
        ans += 1;
    printf("%d\n", ans);
}
int main()
{
    int t = 1;
    //scanf("%d", &t);
    while (t--)
        solve();
    return 0;
}