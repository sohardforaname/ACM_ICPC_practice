#include <bits/stdc++.h>
using namespace std;
const int N = 3e2 + 5;
int ans[N][N];
int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            ans[i][j] = i + n * (j - 1);
    for (int i = 2; i <= n; i += 2)
        for (int j = 1; j <= n / 2; ++j)
            swap(ans[j][i], ans[n - j + 1][i]);
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            printf("%d%c", ans[i][j], " \n"[j == n]);
    return 0;
}