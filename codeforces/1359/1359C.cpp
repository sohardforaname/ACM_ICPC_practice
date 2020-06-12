#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int h, c, x;
    scanf("%d%d%d", &h, &c, &x);
    if ((c + h) >> 1 >= x)
    {
        printf("2\n");
        return;
    }
    if (x == h)
    {
        printf("1\n");
        return;
    }
    int b = (x - h) / (h + c - 2 * x);
    int ans = b;
    double ans1 = abs(x - ((1.0 * (1ll * h + c) * b + h) / (2.0 * b + 1ll)));
    double ans2 = abs(x - ((1.0 * (1ll * h + c) * (b + 1) + h) / (2.0 * b + 3ll)));
    if (ans1 > ans2)
        ++ans;
    printf("%d\n", ans * 2 + 1);
}
int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
        solve();
    return 0;
}