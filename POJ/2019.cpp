#include <cmath>
#include <cstdio>
using namespace std;
#define max(a, b) (a > b ? a : b)
#define min(a, b) (a < b ? a : b)
int mat[255][255];
int maxn[255][255][8][8];
int minn[255][255][8][8];
int maxm(int a, int b, int c, int d)
{
    if (a < b)
        a = b;
    if (a < c)
        a = c;
    if (a < d)
        a = d;
    return a;
}
int minm(int a, int b, int c, int d)
{
    if (a > b)
        a = b;
    if (a > c)
        a = c;
    if (a > d)
        a = d;
    return a;
}
void init(int n, int m)
{
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            scanf("%d", &mat[i][j]);
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
        {
            maxn[i][j][0][0] = mat[i][j];
            minn[i][j][0][0] = mat[i][j];
            //printf("%d %d\n",maxn[i][j][0][0],minn[i][j][0][0]);
        }
    for (int k = 0; (1 << k) <= n; ++k)
        for (int l = 0; (1 << l) <= m; ++l)
            if (k + l)
                for (int i = 1; i + (1 << k) - 1 <= n; ++i)
                    for (int j = 1; j + (1 << l) - 1 <= m; ++j)
                    {
                        if (l)
                            maxn[i][j][k][l] = max(maxn[i][j][k][l - 1], maxn[i][j + (1 << (l - 1))][k][l - 1]),
                            minn[i][j][k][l] = min(minn[i][j][k][l - 1], minn[i][j + (1 << (l - 1))][k][l - 1]);
                        if (k)
                            maxn[i][j][k][l] = max(maxn[i][j][k - 1][l], maxn[i + (1 << (k - 1))][j][k - 1][l]),
                            minn[i][j][k][l] = min(minn[i][j][k - 1][l], minn[i + (1 << (k - 1))][j][k - 1][l]);
                    }
}
int maxquery(int l, int r, int x, int y)
{
    int a = log2(r - l + 1);
    int b = log2(y - x + 1);
    return maxm(maxn[l][x][a][b], maxn[r - (1 << a) + 1][x][a][b],
                maxn[l][y - (1 << b) + 1][a][b], maxn[r - (1 << a) + 1][y - (1 << b) + 1][a][b]);
}
int minquery(int l, int r, int x, int y)
{
    int a = log2(r - l + 1);
    int b = log2(y - x + 1);
    return minm(minn[l][x][a][b], minn[r - (1 << a) + 1][x][a][b],
                minn[l][y - (1 << b) + 1][a][b], minn[r - (1 << a) + 1][y - (1 << b) + 1][a][b]);
}
int main()
{
    int n, b, k, a, c;
    scanf("%d%d%d", &n, &b, &k);
    init(n, n);
    for (int i = 0; i < k; ++i)
    {
        scanf("%d%d", &a, &c);
        printf("%d\n", maxquery(a, a + b - 1, c, c + b - 1) - minquery(a, a + b - 1, c, c + b - 1));
    }
    return 0;
}
