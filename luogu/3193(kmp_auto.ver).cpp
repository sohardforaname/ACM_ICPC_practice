#include "../base.h"

const int N = 2e1 + 5, M = 1e1;
bool multi = 0;

int nxt[N][M];
char s[N];
bool f[N];
struct mat
{
    ll a[N][N];
    mat() { memset(a, 0, sizeof(a)); }
};
ll mod;
int n, m;

int idx(const char &s)
{
    return s - '0';
}

mat mul(const mat &a, const mat &b, int len, ll mod)
{
    mat c;
    for (int i = 0; i <= len; ++i)
        for (int j = 0; j <= len; ++j)
            for (int k = 0; k <= len; ++k)
                (c.a[i][j] += a.a[i][k] * b.a[k][j]) %= mod;
    return c;
}

mat pow(mat a, ll b, int len, ll mod)
{
    mat res;
    for (int i = 0; i < len; ++i)
        res.a[i][i] = 1;
    while (b)
    {
        if (b & 1)
            res = mul(res, a, len, mod);
        a = mul(a, a, len, mod);
        b >>= 1;
    }
    return res;
}

void solve()
{
    io(n, m, mod);
    io(s + 1);
    for (int i = 1, fail = 0; i <= m; ++i)
    {
        fail = nxt[fail][idx(s[i])];
        nxt[i - 1][idx(s[i])] = i;
        for (int j = 0; j < M; ++j)
            nxt[i][j] = nxt[fail][j];
    }
    f[m] = 1;
    mat mt;
    for (int i = 0; i <= m; ++i)
    {
        if (f[i])
            continue;
        for (int j = 0; j < M; ++j)
        {
            if (f[nxt[i][j]])
                continue;
            ++mt.a[i][nxt[i][j]];
        }
    }
    mt = pow(mt, n, m, mod);
    ll ans = 0;
    for (int i = 0; i <= m; ++i)
        util.addm(ans, mt.a[0][i], mod);
    io(ans, '\n');
}

MAIN_FUNC