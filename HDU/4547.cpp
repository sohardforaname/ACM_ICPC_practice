#include <bits/stdc++.h>
using namespace std;
int f[100005][20], dep[100005];
bool in[100005];
vector<int> E[100005];
map<string, int> m;
int dfs(int u, int v)
{
    dep[v] = dep[u] + 1;
    f[v][0] = u;
    for (int i = 1; i < 20; ++i)
        f[v][i] = f[f[v][i - 1]][i - 1];
    for (auto i : E[v])
        dfs(v, i);
}
int LCA(int x, int y)
{
    if (dep[x] < dep[y])
        swap(x, y);
    for (int i = 19; i >= 0; --i)
        if (dep[x] - (1 << i) >= dep[y])
            x = f[x][i];
    if (x == y)
        return x;
    for (int i = 19; i >= 0; --i)
        if (f[x][i] != f[y][i])
            x = f[x][i], y = f[y][i];
    return f[x][0];
}
void init(int n)
{
    for (int i = 1; i <= n; ++i)
    {
        dep[i] = 0;
        in[i] = 0;
        for (int j = 0; j < 20; ++j)
            f[i][j] = 0;
        E[i].clear();
    }
}
string str1, str2;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T, n, pos, k;
    cin >> T;
    while (T--)
    {
        cin >> n >> k;
        m.clear();
        pos = 0;
        init(n);
        for (int i = 1; i < n; ++i)
        {
            cin >> str1 >> str2;
            if (m.find(str1) == m.end())
                m[str1] = ++pos;
            if (m.find(str2) == m.end())
                m[str2] = ++pos;
            in[m[str1]] = 1;
            E[m[str2]].push_back(m[str1]);
        }
        dep[0] = 0;
        for (int i = 1; i <= n; ++i)
            if (!in[i])
            {
                dfs(0, i);
                break;
            }
        for (int i = 0; i < k; ++i)
        {
            cin >> str1 >> str2;
            int a = dep[m[str1]], b = dep[LCA(m[str1], m[str2])], c = dep[m[str2]];
            cout << a - b + ((b == c) ? 0 : 1) << endl;
        }
    }
    return 0;
}
