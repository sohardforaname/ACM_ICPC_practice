#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e2 + 5;
int a[N];
bool vis[N << 1];
void solve()
{
    int n, x;
    scanf("%d%d", &n, &x);
    memset(vis, 0, sizeof(vis));
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d", &a[i]);
        vis[a[i]] = 1;
    }
    int pos = 1;
    while (x)
    {
        while (vis[pos])
            ++pos;
        vis[pos] = 1;
        ++pos;
        --x;
    }
    int i = 1;
    for (; vis[i]; ++i)
        ;
    printf("%d\n", i - 1);
}
int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
        solve();
    return 0;
}