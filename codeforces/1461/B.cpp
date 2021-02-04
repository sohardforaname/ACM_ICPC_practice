#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 5e2 + 5;
char s[N][N];
int l[N][N], r[N][N];
void solve()
{
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i)
        scanf("%s", &s[i][1]);
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
            l[i][j] = 0x3f3f3f3f, r[i][j] = 0;
        for (int j = 1; j <= m; ++j)
        {
            if (s[i][j - 1] == '*')
                l[i][j] = l[i][j - 1];
            else
                l[i][j] = j;
        }
        for (int j = m; j; --j)
        {
            if (s[i][j + 1] == '*')
                r[i][j] = r[i][j + 1];
            else
                r[i][j] = j;
        }
    }
    ll ans = 0;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            if (s[i][j] == '*')
                for (int k = 0; k <= n - i; ++k)
                {
                    if (l[k + i][j + k] > j - k || r[k + i][j - k] < j + k)
                        break;
                    //printf("%d %d\n", i, j);
                    ++ans;
                }
    printf("%lld\n", ans);
}
int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
        solve();
    return 0;
}