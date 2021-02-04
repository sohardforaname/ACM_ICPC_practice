#include "../base.h"

const int N = 3e4 + 5;
bool multi = 0;

int n, m;
vi dog[N];
bitset<N> vis[N];
bool pvis[N];
queue<tuple<int, int, int>> q;

void push(int p, int l, int st)
{
    if (!pvis[p])
    {
        pvis[p] = 1;
        for (auto i : dog[p])
            if (!vis[p].test(i))
            {
                vis[p].set(i);
                q.push({p, i, st});
            }
    }
    if (!vis[p].test(l))
    {
        vis[p].set(l);
        q.push({p, l, st});
    }
}

void solve()
{
    int s, t;
    io(n, m);
    for (int i = 0; i < m; ++i)
    {
        int b, p;
        io(b, p);
        if (i == 0)
            s = b;
        else if (i == 1)
            t = b;
        dog[b].push_back(p);
    }
    pvis[s] = 1;
    for (auto i : dog[s])
        if (!vis[s].test(i))
        {
            vis[s].set(i);
            q.push({s, i, 0});
        }
    while (q.size())
    {
        int p, l, st;
        tie(p, l, st) = q.front();
        q.pop();
        if (p == t)
            return void(io(st, '\n'));
        if (p - l >= 0)
            push(p - l, l, st + 1);
        if (p + l < n)
            push(p + l, l, st + 1);
    }
    io(-1, '\n');
}
int main()
{
    int t;
    if (multi)
        io(t);
    else
        t = 1;
    while (t--)
        solve();
    return 0;
}