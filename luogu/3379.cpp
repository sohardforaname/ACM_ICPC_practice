#include <bits/stdc++.h>
#pragma GCC optimize(3)
using namespace std;
const int MAXN = 500005;
vector<int> E[MAXN];
int in[MAXN], out[MAXN * 2], dep[MAXN], st[MAXN * 2][20], rec[MAXN * 2][20], t;
bool vis[MAXN];
void dfs(int u, int pre)
{
    in[u] = ++t;
    st[t][0] = u;
    for (auto &i : E[u])
    {
        if (!vis[i] && i != pre)
        {
            dep[i] = dep[u] + 1;
            dfs(i, u);
            vis[i] = 1;
            st[++t][0] = u;
        }
    }
}
void getst(int n)
{
    for (int i = 1; (1 << i) <= n; ++i)
        for (int j = 1; j + (1 << i) - 1 <= n; ++j)
        {
            st[j][i] = st[j][i - 1];
            if (dep[st[j][i - 1]] > dep[st[j + (1 << (i - 1))][i - 1]])
                st[j][i] = st[j + (1 << (i - 1))][i - 1];
        }
}
int LCA(int x, int y)
{
    int f = int(log2(y - x + 1) / log2(2.0));
    if (dep[st[x][f]] <= dep[st[y - (1 << f) + 1][f]])
        return st[x][f];
    else
        return st[y - (1 << f) + 1][f];
}
void init(int n)
{
    for (int i = 1; i <= n; ++i)
    {
        E[i].clear();
        dep[i] = 0;
    }
    t = 0;
    memset(st, 0, sizeof(st));
}
int main()
{
    int n, m, s, a, b;
    scanf("%d%d%d", &n, &m, &s);
    init(n);
    for (int i = 0; i < n - 1; ++i)
    {
        scanf("%d%d", &a, &b);
        E[a].push_back(b);
        E[b].push_back(a);
    }
    dfs(s, 0);
    getst(t);
    /*for(int i=0;i<=log2(t)+1;++i)
        for(int j=0;j<=t;++j)
            cout<<st[j][i]<<((j==t)?'\n':' '); */
    for (int i = 0; i < m; ++i)
    {
        scanf("%d%d", &a, &b);
        if (in[a] > in[b])
            swap(a, b);
        //cout<<in[a]<<" "<<in[b]<<endl;
        printf("%d\n", LCA(in[a], in[b]));
    }
    return 0;
}
