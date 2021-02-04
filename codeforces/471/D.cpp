#include "../base.h"

bool multi = 0;
const int N = 2e5 + 5;

int a[N], b[N];
int nxt[N];
void getnext(int *s, int len)
{
    int j;
    nxt[0] = j = -1;
    int k = 0;
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
    int ans = 0;
    int j = 0, k = 0;
    while (k < lent)
    {
        if (j == -1 || s[j] == t[k])
            ++j, ++k;
        else
            j = nxt[j];
        if (j == lens)
        {
            ++ans;
            j = nxt[j];
        }
    }
    return ans;
}
void solve()
{
    int n, m;
    io(n, m);
    for (int i = 0; i < n; ++i)
        io(a[i]);
    --n;
    for (int i = 0; i < n; ++i)
        a[i] = a[i + 1] - a[i];
    for (int i = 0; i < m; ++i)
        io(b[i]);
    --m;
    for (int i = 0; i < m; ++i)
        b[i] = b[i + 1] - b[i];
    if (!n || !m)
        return void(io(max(n, m) + 1, '\n'));
    if (n > m)
    {
        swap(n, m);
        swap(a, b);
    }
    getnext(a, n);
    io(kmp(a, n, b, m), '\n');
}
MAIN_FUNC

/*
rustup toolchain link myrust "F:\rust\rustup\toolchains\stable-x86_64-pc-windows-msvc"
*/