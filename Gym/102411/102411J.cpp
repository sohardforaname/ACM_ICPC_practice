#include <bits/stdc++.h>
using namespace std;
const int N = 5e2 + 5;
int G[N][N];
int ans[N][N];
char s[N];
int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
    {
        scanf("%s", s + 1);
        for (int j = 1; j <= n; ++j)
            G[i][j] = s[j] - '0';
    }
    for (int i = 1; i <= n; ++i)
        for (int j = i + 1; j <= n; ++j)
        {
            ans[i][j] = G[i][j];
            if (!G[i][j])
                continue;
            for (int k = i + 1; k <= n; ++k)
            {
                G[i][k] -= G[j][k];
                if (G[i][k] < 0)
                    G[i][k] += 10;
            }
        }
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
            printf("%d", ans[i][j]);
        putchar('\n');
    }
    return 0;
}