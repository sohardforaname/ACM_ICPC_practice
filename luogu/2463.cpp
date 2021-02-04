#include "../base.h"

const int N = 1e3 + 5;
bool multi = 0;

int a[N][N], s[N];
int len[N];
int nxt[N];
void getnext(int *s, int len)
{
    int j, k = 0;
    j = nxt[0] = -1;
    while (k < len)
    {
        if (j == -1 || s[j] == s[k])
            nxt[++k] = ++j;
        else
            j = nxt[j];
    }
}
int kmp(int *s, int lens, int *t, int lent)
{
    int j = 0, k = 0;
    int ans = 0;
    while (k < lent)
    {
        if (j == -1 || s[j] == t[k])
            ++j, ++k;
        else
            j = nxt[j];
        util.cmax(ans, j);
        if (j == lens)
            j = nxt[j];
    }
    return ans;
}
void solve()
{
    int n;
    io(n);
    for (int i = 1; i <= n; ++i)
    {
        io(len[i]);
        for (int j = 0; j < len[i]; ++j)
            io(a[i][j]);
    }
    int minn = 1e3, minpos = 0;
    for (int i = 1; i <= n; ++i)
        if (minn > len[i])
            minn = len[i], minpos = i;
    for (int i = 1; i <= n; ++i)
    {
        --len[i];
        for (int j = 0; j < len[i]; ++j)
            a[i][j] = a[i][j + 1] - a[i][j];
    }
    int ans = 0;
    for (int i = 1; i <= len[minpos]; ++i)
    {
        int l = len[minpos];
        int *s = &a[minpos][l - i];
        getnext(s, i);
        int res = 1e3;
        for (int j = 1; j <= n; ++j)
            util.cmin(res, kmp(s, i, a[j], len[j]));
        util.cmax(ans, res);
    }
    io(ans + 1, '\n');
}

MAIN_FUNC