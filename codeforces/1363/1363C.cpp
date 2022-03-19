#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int deg[N];
void solve()
{
    int n, x;
    scanf("%d%d", &n, &x);
    memset(deg, 0, sizeof(deg[0]) * (n + 1));
    for (int i = 1; i < n; ++i)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        ++deg[u], ++deg[v];
    }
    if (deg[x] <= 1)
    {
        printf("Ayush\n");
        return;
    }
    printf("%s", n % 2 ? "Ashish\n" : "Ayush\n");
}
int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
        solve();
    return 0;
}