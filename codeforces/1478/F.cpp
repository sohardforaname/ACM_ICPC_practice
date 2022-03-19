#include "../base.h"

bool multi = 0;
const int N = 5e3 + 5;
pair<ll, ll> p[N];
ll d[N][N];

ll getdis(int i, int j)
{
    return (p[i].first - p[j].first) * (p[i].first - p[j].first)
        + (p[i].second - p[j].second) * (p[i].second - p[j].second);
}
bool vis[N];

void solve()
{
    int n;
    io(n);
    for (int i = 1; i <= n; ++i)
        io(p[i].first, p[i].second);
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            if (i != j)
                d[i][j] = getdis(i, j);
    int pos = 1;
    for (int i = 1; i <= n; ++i) {
        ll maxn = 0, nxtp = 0;
        for (int j = 1; j <= n; ++j) {
            if (vis[j])
                continue;
            if (d[pos][j] > maxn) {
                maxn = d[pos][j];
                nxtp = j;
            }
        }
        pos = nxtp;
        io(pos, " \n"[i == n]);
        vis[pos] = 1;
    }
}

MAIN_FUNC