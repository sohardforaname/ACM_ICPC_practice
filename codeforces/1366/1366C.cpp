#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
typedef long long ll;
typedef pair<int, int> pii;
int buc[105];
void solve()
{
    memset(buc, 0, sizeof(buc));
    int n, m, a;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
        {
            scanf("%d", &a);
            buc[i + j] += a;
        }
    int ans = 0;
    for (int i = 2; i <= (n + m) / 2; ++i)
    {
        int one = buc[i] + buc[n + m - i + 2];
        int size;
        if (i <= min(n, m))
            size = (i - 1) * 2;
        else
            size = min(n, m) * 2;
        ans += min(one, size - one);
    }
    if ((n + m) % 2 == 1)
    {
        int size = min(n, m) * 2;
        int one = buc[(n + m) / 2 + 1] + buc[(n + m) / 2 + 2];
        ans += min(one, size - one);
    }
    printf("%d\n", ans);
}
int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
        solve();
    return 0;
}