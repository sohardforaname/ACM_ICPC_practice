#include <bits/stdc++.h>
using namespace std;
const int N = 4e2 + 5;
char mp[N][N], mod[10][10];
int n, m;
void dfs(int x, int y, int len, int div)
{
    if (div == m)
        return;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
        {
            int xlen = len / n, ylen = len / n;
            if (mod[i][j] == '*')
            {
                for (int k = 1; k <= xlen; ++k)
                    for (int l = 1; l <= xlen; ++l)
                        mp[k + xlen * i][l + ylen * j] = mod[i][j];
            }
            else
                dfs(xlen * i, ylen * j, len / n, div + 1);
        }
}
int main()
{

    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i)
        scanf("%s", &mod[i][1]);
    dfs(1, 1, pow(n, m), 0);
    int len = pow(n, m);
    for (int i = 1; i <= len; ++i)
    {
        for (int j = 1; j <= len; ++j)
            putchar(mp[i][j] ? '*' : '.');
        putchar('\n');
    }
    return 0;
}
void phi_table(int n)
{
    memset(phi, 0, sizeof(phi));
    phi[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        if (!phi[i])
        {
            for (int j = i; j <= n; j += i)
            {
                if (!phi[j])
                    phi[j] = j;
                phi[j] = phi[j] / i * (i - 1);
            }
        }
    }
}