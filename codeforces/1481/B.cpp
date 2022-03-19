#include "../base.h"

bool multi = 1;
const int N = 1e2 + 5;
int h[N];

int check(int n)
{
    for (int i = 1; i <= n; ++i)
        if (h[i] < h[i + 1])
        {
            ++h[i];
            return i;
        }
    assert(0);
    return 0;
}

void solve()
{
    int n, k;
    io(n, k);
    for (int i = 1; i <= n; ++i)
        io(h[i]);
    h[n + 1] = 1e9;
    int pos = 0;
    for (int i = 1; i <= k; ++i)
    {
        pos = check(n);
        if (pos == n)
            return void(io(-1, '\n'));
    }
    io(pos, '\n');
}

MAIN_FUNC