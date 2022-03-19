#include "../base.h"

bool multi = 0;
const int N = 1e5 + 5, M = 1e5 + 5;
vector<int> G[M];
int b[N];

void solve()
{
    int ty, n, q, m;
    io(ty, n, q, m);
    for (int i = 1, a; i <= n; ++i)
    {
        io(a);
        G[a].push_back(i);
    }
    for (int i = 1, l; i <= q; ++i)
    {
        io(l);
        bool f = 1;
        for (int j = 1; j <= l; ++j)
            io(b[j]);
        for (int j = 1, pos = -1; j <= l; ++j)
        {
            auto it = upper_bound(G[b[j]].begin(), G[b[j]].end(), pos);
            if (it == G[b[j]].end())
            {
                f = 0;
                break;
            }
            pos = *it;
        }
        if (f)
            io("Yes", '\n');
        else
            io("No", '\n');
    }
}

MAIN_FUNC