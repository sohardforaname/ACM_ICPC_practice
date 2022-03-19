#include "../base.h"

bool multi = 1;
const int N = 1e5 + 5;
vector<int> G[N], G1[N], ans;
int a[N], b[N], c[N];
void solve()
{
    int n, m;
    io(n, m);

    ans.clear();
    for (int i = 1; i <= n; ++i)
        G[i].clear(), G1[i].clear();

    for (int i = 1; i <= n; ++i)
        io(a[i]);
    for (int i = 1; i <= n; ++i)
        io(b[i]);
    for (int i = 1; i <= m; ++i)
        io(c[i]);
    for (int i = 1; i <= n; ++i) {
        if (a[i] != b[i])
            G[b[i]].push_back(i);
        else
            G1[b[i]].push_back(i);
    }
    int lst = 0;
    if (G[c[m]].size())
        lst = G[c[m]].back(), ans.push_back(lst), G[c[m]].pop_back();
    else if (G1[c[m]].size())
        lst = G1[c[m]].back(), ans.push_back(lst);
    else
        return void(io("NO", '\n'));

    for (int i = m - 1; i; --i) {
        if (G[c[i]].size())
            ans.push_back(G[c[i]].back()), G[c[i]].pop_back();
        else if (G1[c[i]].size())
            ans.push_back(G1[c[i]].back());
        else
            ans.push_back(lst);
    }

    for (int i = 1; i <= n; ++i)
        if (G[i].size())
            return void(io("NO", '\n'));

    io("YES", '\n');
    reverse(ans.begin(), ans.end());
    dbg(ans);
}

MAIN_FUNC