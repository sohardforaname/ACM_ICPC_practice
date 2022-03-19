#include <bits/stdc++.h>
using namespace std;
const int N = 5e1 + 5;
void solve()
{
    int n, m;
    scanf("%d%d", &n, &m);
    if (m & 1 || m > n * 4 || 16 * n > m * m)
    {
        printf("No\n");
        return;
    }
    printf("Yes\n");
    if (m >= 2 * n + 2)
    {
        int a = (m - 2 * n - 2) / 2, b = n - a;
        for (int i = 1; i <= b; ++i)
            printf("1 %d\n", i);
        for (int i = 1; i <= a; ++i)
            printf("10 %d\n", i * 2);
    }
    else
    {
        int a = m / 4, b = m / 2 - a;
        for (int i = 1; i <= a; ++i)
            printf("1 %d\n", i);
        for (int i = 2; i <= b; ++i)
            printf("%d 1\n", i);
        int cnt = n - a - b + 1;
        for (int i = 2; i <= b; ++i)
            for (int j = 2; j <= a; ++j)
            {
                printf("%d %d\n", i, j);
                if (--cnt == 0)
                    goto lab;
            }
    }
lab:;
}
int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
        solve();
    return 0;
}