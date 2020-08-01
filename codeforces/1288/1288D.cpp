#include <bits/stdc++.h>
using namespace std;
const int N = 3e5 + 5;
int n, m, px, py;
int a[N][15];
int buc[305];
bool check(int x)
{
    memset(buc, 0, sizeof(buc));
    for (int i = 1; i <= n; ++i)
    {
        int tmp = 0;
        for (int j = 1; j <= m; ++j)
            tmp |= (a[i][j] >= x) << (j - 1);
        buc[tmp] = i;
    }
    for (int i = 0; i < (1 << m); ++i)
        for (int j = 0; j < (1 << m); ++j)
            if (buc[i] && buc[j] && (i | j) == (1 << m) - 1)
            {
                px = buc[i], py = buc[j];
                return true;
            }
    return false;
}
void solve()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            scanf("%d", &a[i][j]);
    int l = 0, r = 1e9 + 5;
    while (l < r)
    {
        int m = (l + r) >> 1;
        if (!check(m))
            r = m;
        else
            l = m + 1;
    }
    if (!l)
        printf("1 1\n");
    else
        printf("%d %d\n", px, py);
}
int main()
{
    int T = 1;
    //scanf("%d", &T);
    while (T--)
        solve();
    return 0;
}