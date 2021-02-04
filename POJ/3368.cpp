#include <cmath>
#include <cstdio>
#define max(a, b) (a > b ? a : b)
int num[100005];
int seq[100005];
int end[100005];
int st[100005][17];
void init(int n)
{
    for (int i = 1; i <= n; ++i)
        scanf("%d", &num[i]);
    int pre = -999999;
    for (int i = 1; i <= n; ++i)
    {
        if (pre != num[i])
            seq[i] = 1, pre = num[i];
        else
            seq[i] = seq[i - 1] + 1;
        //printf("%d\n",seq[i]);
    }
    int pos = n;
    bool tag = 0;
    for (int i = n; i >= 1; --i)
    {
        if (tag == 1)
        {
            tag = 0;
            pos = i;
        }
        if (seq[i] == 1)
            tag = 1;
        end[i] = pos;
        //printf("%d\n",end[i]);
    }
    for (int i = 1; i <= n; ++i)
        st[i][0] = seq[i];
    for (int j = 1; (1 << j) <= n; ++j)
        for (int i = 1; i + (1 << j) - 1 <= n; ++i)
            st[i][j] = max(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
}
int query(int l, int r)
{
    int k = log2(r - l + 1);
    return max(st[l][k], st[r - (1 << k) + 1][k]);
}
int main()
{
    int n, m, a, b;
    while (scanf("%d", &n) && n)
    {
        scanf("%d", &m);
        init(n);
        for (int i = 0; i < m; ++i)
        {
            scanf("%d%d", &a, &b);
            if (b <= end[a])
                printf("%d\n", b - a + 1);
            else
                printf("%d\n", max(end[a] - a + 1, query(end[a] + 1, b)));
        }
    }
    return 0;
}
