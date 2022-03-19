#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
typedef long long ll;
vector<int> G[N], lef;
void dfs(int u, int fa)
{
    if (G[u].size() == 1)
    {
        lef.push_back(u);
        return;
    }
    for (auto i : G[u])
        if (i != fa)
            dfs(i, u);
}
void solve()
{
    int n;
    scanf("%d", &n);
    for (int i = 1; i < n; ++i)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        G[u].push_back(v);
        G[v].push_back(u);
    }
    if (n == 1)
    {
        printf("0\n");
        return;
    }
    if (n == 2)
    {
        printf("1\n1 2\n");
        return;
    }
    int rt = 0;
    for (int i = 1; i <= n; ++i)
        if (G[i].size() != 1)
        {
            rt = i;
            break;
        }
    dfs(rt, 0);
    printf("%d\n", (lef.size() + 1) / 2);
    for (int i = 0; i < lef.size() / 2; ++i)
        printf("%d %d\n", lef[i], lef[i + (lef.size() + 1) / 2]);
    if (lef.size() % 2)
        printf("%d %d\n", lef[lef.size() / 2], rt);
}
int main()
{
    int T = 1;
    //scanf("%d", &T);
    while (T--)
        solve();
    return 0;
}