#include "../base.h"

const int N = 1e4 + 5;
bool multi = 1;
ll a[N], tms[10];
void solve()
{
    fill(tms, tms + 10, 1e17);
    int n, d;
    scanf("%d%d", &n, &d);
    for (int i = 1; i <= 20; ++i)
    {
        if (tms[(d * i) % 10] != 1e17)
            continue;
        tms[(d * i) % 10] = i;
    }
    for (int i = 1; i <= n; ++i)
    {
        scanf("%lld", a + i);
        if (tms[a[i] % 10] * d <= a[i])
            printf("YES\n");
        else if (d * 10ll <= a[i])
            printf("YES\n");
        else
            printf("NO\n");
    }
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