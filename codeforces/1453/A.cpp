#include <bits/stdc++.h>
using namespace std;
const int N = 1e2 + 5;
int a[N];
void solve()
{
    memset(a, 0, sizeof(a));
    int n, m, x;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &x), ++a[x];
    for (int i = 1; i <= m; ++i)
        scanf("%d", &x), ++a[x];
    int ans = 0;
    for (int i = 1; i <= 100; ++i)
        if (a[i] == 2)
            ++ans;
    printf("%d\n", ans);
}
int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
        solve();
    return 0;
}