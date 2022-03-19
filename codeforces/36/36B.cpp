#include <bits/stdc++.h>
using namespace std;
const int N = 4e2 + 5;
char mp[N][N], mod[10][10];
int n, m;
void dfs(int x, int y, int len, int div)
{
    if (div == m)
        return;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
        {
            int xlen = len / n, ylen = len / n;
            if (mod[i][j] == '*')
            {
                for (int k = 0; k < xlen; ++k)
                    for (int l = 0; l < xlen; ++l)
                        mp[x + k + xlen * i][y + l + ylen * j] = mod[i][j];
            }
            else
                dfs(x + xlen * i, y + ylen * j, len / n, div + 1);
        }
}
int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++i)
        scanf("%s", mod[i]);
    dfs(0, 0, pow(n, m), 0);
    int len = pow(n, m);
    for (int i = 0; i < len; ++i)
    {
        for (int j = 0; j < len; ++j)
            putchar(mp[i][j] ? '*' : '.');
        putchar('\n');
    }
    return 0;
}