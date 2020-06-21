#include <cstdio>
#include <cstring>
using namespace std;
const int N = 35;
struct Mat
{
    int m[N << 1][N << 1];
    Mat()
    {
        memset(m, 0, sizeof(m));
    }
};
Mat mul(const Mat &a, const Mat &b, int p, int n)
{
    Mat res;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            for (int k = 1; k <= n; ++k)
                (res.m[i][j] += a.m[i][k] * b.m[k][j]) %= p;
    return res;
}
Mat pow(Mat a, int b, int p, int n)
{
    Mat res;
    for (int i = 1; i <= n; ++i)
        res.m[i][i] = 1;
    while (b)
    {
        if (b & 1)
            res = mul(res, a, p, n);
        a = mul(a, a, p, n);
        b >>= 1;
    }
    return res;
}
Mat mat;
int main()
{
    int n, m, k;
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            scanf("%d", &mat.m[i][j]);
    for (int i = n + 1; i <= n * 2; ++i)
    {
        mat.m[i][i] = 1;
        for (int j = 1; j <= n; ++j)
            mat.m[j][i] = mat.m[j][i - n];
    }
    mat = pow(mat, m, k, n * 2);
    for (int i = 1; i <= n; ++i)
        for (int j = n + 1; j <= n * 2; ++j)
            printf("%d%c", mat.m[i][j] % k, " \n"[j == n * 2]);
    return 0;
}