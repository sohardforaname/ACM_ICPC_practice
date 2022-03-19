#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int n, p, c, p1 = 0, c1 = 0;
    scanf("%d", &n);
    bool f = 0;
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d%d", &p, &c);
        if (p < p1 || c < c1 || (p - p1) < (c - c1))
            f = 1;
        p1 = p, c1 = c;
    }
    printf("%s", f ? "NO\n" : "YES\n");
}
int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
        solve();
    return 0;
}