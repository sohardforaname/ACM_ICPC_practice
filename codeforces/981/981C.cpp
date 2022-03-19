#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
vector<int> G[N];
int deg[N];
vector<int> d;
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
        ++deg[u], ++deg[v];
    }
    if (n == 2)
    {
        printf("Yes\n1\n1 2\n");
        return;
    }
    int cnt = 0, maxd = 0, maxpos = 0;
    for (int i = 1; i <= n; ++i)
    {
        maxd = max(maxd, deg[i]);
        if (deg[i] <= 2)
            ++cnt;
        else
            maxpos = i;
        if (deg[i] == 1)
            d.push_back(i);
    }
    if (cnt < n - 1)
        printf("No\n");
    else
    {
        printf("Yes\n%d\n", (d.size() + 1) / 2);
        for (int i = 0; i < d.size() / 2; ++i)
            printf("%d %d\n", d[i * 2], d[i * 2 + 1]);
        if (maxd % 2)
            printf("%d %d\n", d[d.size() - 1], maxpos);
    }
}
int main()
{
    int T = 1;
    //scanf("%d", &T);
    while (T--)
        solve();
    return 0;
}
