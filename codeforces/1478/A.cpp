#include "../base.h"

const int N = 1e2 + 5;
bool multi = 1;
int a[N];
void solve()
{
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        scanf("%d", a + i);
    int maxn = 1, tmp = 1;
    for (int i = 2; i <= n; ++i)
    {
        if (a[i] == a[i - 1])
            ++tmp;
        else
        {
            util.cmax(maxn, tmp);
            tmp = 1;
        }
    }
    util.cmax(maxn, tmp);
    printf("%d\n", maxn);
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