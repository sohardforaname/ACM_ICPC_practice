#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
typedef long long ll;
typedef pair<int, int> pii;
pii a[N], b[N];
void solve()
{
    int n, m;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        scanf("%d%d", &a[i].first, &a[i].second);
    scanf("%d", &m);
    for (int i = 1; i <= m; ++i)
        scanf("%d%d", &b[i].first, &b[i].second);
    sort(a + 1, a + n + 1);
    sort(b + 1, b + m + 1);
    ll ans = 0;
    int pos1 = 1, pos2 = 1;
    while (pos1 <= n || pos2 <= m)
    {
        if (pos1 <= n && pos2 <= m)
        {
            if (a[pos1].first < b[pos2].first)
                ans += a[pos1++].second;
            else if (a[pos1].first > b[pos2].first)
                ans += b[pos2++].second;
            else
            {
                ans += max(a[pos1].second, b[pos2].second);
                ++pos1, ++pos2;
            }
        }
        else if (pos1 > n)
            ans += b[pos2++].second;
        else
            ans += a[pos1++].second;
    }
    printf("%lld\n", ans);
}
int main()
{
    int T = 1;
    //scanf("%d", &T);
    while (T--)
        solve();
    return 0;
}