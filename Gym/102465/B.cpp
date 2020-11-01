#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int a[N], b[N];
int minn[N][20], maxn[N][20];
void initst(int n)
{
    for (int i = 1; i <= n; ++i)
        maxn[i][0] = a[i], minn[i][0] = b[i];
    for (int j = 1; (1 << j) <= n; ++j)
        for (int i = 1; i + (1 << j) - 1 <= n; ++i)
        {
            minn[i][j] = min(minn[i][j - 1], minn[i + (1 << (j - 1))][j - 1]);
            maxn[i][j] = max(maxn[i][j - 1], maxn[i + (1 << (j - 1))][j - 1]);
        }
}
int querymax(int l, int r)
{
    int k = log2(r - l + 1);
    return max(maxn[l][k], maxn[r - (1 << k) + 1][k]);
}
int querymin(int l, int r)
{
    int k = log2(r - l + 1);
    return min(minn[l][k], minn[r - (1 << k) + 1][k]);
}
bool check(int len, int n)
{
    for (int i = 1; i <= n - len + 1; ++i)
        if (querymin(i, i + len - 1) - querymax(i, i + len - 1) + 1 >= len)
            return 1;
    return 0;
}
int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d%d", &a[i], &b[i]);
        ++a[i], ++b[i];
    }
    initst(n);
    int l = 1, r = n + 1;
    while (l < r)
    {
        int m = (l + r) >> 1;
        if (!check(m, n))
            r = m;
        else
            l = m + 1;
    }
    printf("%d\n", l - 1);
    return 0;
}
