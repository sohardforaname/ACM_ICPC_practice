#include <algorithm>
#include <cstdio>
using namespace std;
const int N = 1e2 + 5;
int mat[N][N];
int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            scanf("%d", &mat[i][j]);
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            mat[i][j] = mat[i][j] + mat[i - 1][j] + mat[i][j - 1] - mat[i - 1][j - 1];
    int maxn = -0x3f3f3f3f;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            for (int k = 1; k <= n - i; ++k)
                for (int l = 1; l <= n - j; ++l)
                    maxn = max(maxn, mat[k + i][l + j] - mat[k + i][l - 1] - mat[k - 1][l + j] + mat[k - 1][l - 1]);
    printf("%d\n", maxn);
    return 0;
}