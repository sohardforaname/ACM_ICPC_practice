#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 5;
bool vis1[N], vis2[N];
void solve()
{
    int n, m;
    scanf("%d%d", &n, &m);
    memset(vis1, 0, sizeof(vis1));
    memset(vis2, 0, sizeof(vis2));
    int a;
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d", &a);
        vis1[a] = 1;
    }
    for (int i = 1; i <= m; ++i)
    {
        scanf("%d", &a);
        vis2[a] = 1;
    }
    for (int i = 1; i <= 1e3; ++i)
        if (vis1[i] && vis2[i])
        {
            printf("YES\n1 %d\n", i);
            return;
        }
    printf("NO\n");
}
int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
        solve();
    return 0;
}