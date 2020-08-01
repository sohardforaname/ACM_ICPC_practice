#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e2 + 5;
int c[N];
vector<int> G[N];
void solve()
{
    int n, m, q;
    scanf("%d%d%d", &n, &m, &q);
    for (int i = 1; i <= m; ++i)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        G[u].push_back(v);
        G[v].push_back(u);
    }
    for (int i = 1; i <= n; ++i)
        scanf("%d", &c[i]);
    for (int i = 1; i <= q; ++i)
    {
        int a, x, y;
        scanf("%d", &a);
        if (a == 1)
        {
            scanf("%d", &x);
            printf("%d\n", c[x]);
            for (auto &i : G[x])
                c[i] = c[x];
        }
        else if (a == 2)
        {
            scanf("%d%d", &x, &y);
            printf("%d\n", c[x]);
            c[x] = y;
        }
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