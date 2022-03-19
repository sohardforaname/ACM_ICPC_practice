#include <bits/stdc++.h>
using namespace std;
const int N = 2e2 + 5;
struct p
{
    int x, y;
};
p a[N], f[N];
int main()
{
    int n, m, k;
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 1; i <= k; ++i)
        scanf("%d%d", &a[i].x, &a[i].y);
    for (int i = 1; i <= k; ++i)
        scanf("%d%d", &f[i].x, &f[i].y);
    printf("%d\n", n * m + m + n - 3);
    for (int i = 1; i < n; ++i)
        printf("U");
    for (int i = 1; i < m; ++i)
        printf("L");
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j < m; ++j)
            printf("%c", i % 2 ? 'R' : 'L');
        if (i < n)
            printf("D");
    }
    printf("\n");
    return 0;
}