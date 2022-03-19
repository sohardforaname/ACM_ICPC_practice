#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int n, m, k;
    scanf("%d%d%d", &n, &m, &k);
    int tmp = n / k;
    if (tmp <= m)
        printf("%d\n", int(tmp - ceil((1.0 * m - tmp) / (1.0 * k - 1))));
    else
        printf("%d\n", m);
}
int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
        solve();
    return 0;
}