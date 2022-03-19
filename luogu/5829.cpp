#include "../base.h"

bool multi = 0;
const int N = 1e6 + 5, M = 2e1 + 5;

int nxt[N];
char s[N];
int dep[N], f[N][M];
void getnext(const char *s, int len)
{
    int j = -1, k = 0;
    nxt[0] = j;
    while (k < len)
    {
        if (j == -1 || s[j] == s[k])
        {
            nxt[++k] = ++j;
            f[k][0] = j;
            dep[k] = dep[j] + 1;
        }
        else
            j = nxt[j];
    }
}

void calf(int len)
{
    for (int i = 1; i < M; ++i)
        for (int j = 0; j <= len; ++j)
            f[j][i] = f[f[j][i - 1]][i - 1];
}

int getlca(int u, int v)
{
    u = nxt[u], v = nxt[v];
    if (dep[u] < dep[v])
        swap(u, v);
    int dif = dep[u] - dep[v];
    for (int i = M - 1; ~i; --i)
        if ((dif >> i) & 1)
            u = f[u][i];
    if (u == v)
        return u;
    for (int i = M - 1; ~i; --i)
        if (f[u][i] != f[v][i])
            u = f[u][i], v = f[v][i];
    return f[u][0];
}

void solve()
{
    int q;
    io(s);
    io(q);
    int len = strlen(s);
    getnext(s, len);
    calf(len);
    int u, v;
    for (int i = 1; i <= q; ++i)
    {
        io(u, v);
        io(getlca(u, v), '\n');
    }
}

MAIN_FUNC