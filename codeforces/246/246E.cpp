#include <bits/stdc++.h>
#pragma GCC optimize(2)
using namespace std;
typedef long long ll;
const int N = 1e5 + 5;
set<int> s[N << 1];
vector<int> G[N];
pair<int, int> p[N];
vector<pair<int, int>> q[N];
int ans[N];

string a[N], b[N];
int id[N];

int dep[N], son[N], sz[N];
void dfs1(int u, int fa)
{
    sz[u] = 1;
    dep[u] = dep[fa] + 1;
    for (auto i : G[u])
        if (i != fa)
        {
            dfs1(i, u);
            sz[u] += sz[i];
            if (sz[i] > sz[son[u]])
                son[u] = i;
        }
}

bool vis[N];
void add(int u, int fa, int op)
{
    if (op == 1)
        s[dep[u]].insert(p[u].first);
    else
        s[dep[u]].clear();
    for (auto i : G[u])
        if (i != fa && !vis[i])
            add(i, u, op);
}
void dfs2(int u, int fa, int op)
{
    for (auto i : G[u])
        if (i != fa && i != son[u])
            dfs2(i, u, 0);
    if (son[u])
        dfs2(son[u], u, 1), vis[son[u]] = 1;
    add(u, fa, 1);
    for (auto i : q[u])
        ans[i.first] = s[i.second + dep[u]].size();
    if (son[u])
        vis[son[u]] = 0;
    if (!op)
        add(u, fa, -1);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    int top = 0;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i] >> p[i].second;
        b[++top] = a[i];
    }
    sort(b + 1, b + top + 1);
    top = unique(b + 1, b + top + 1) - (b + 1);
    for (int i = 1; i <= n; ++i)
        p[i].first = lower_bound(b + 1, b + top + 1, a[i]) - b;
    int rt = 0;
    for (int i = 1; i <= n; ++i)
    {
        G[p[i].second].push_back(i);
        G[i].push_back(p[i].second);
    }
    dfs1(rt, 0);
    int m;
    cin >> m;
    for (int i = 1; i <= m; ++i)
    {
        int x, y;
        cin >> x >> y;
        q[x].push_back({i, y});
    }
    dfs2(rt, 0, 0);
    for (int i = 1; i <= m; ++i)
        cout << ans[i] << '\n';
    return 0;
}