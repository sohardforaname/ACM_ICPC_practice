#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 5e1 + 5;
const int M = 1e5 + 5;
int cnt[N];
vector<int> G[M];
void solve()
{
    int n, m, q;
    scanf("%d%d%d", &n, &m, &q);
    for (int i = 1; i <= q; ++i)
    {
        int a, b, c;
        scanf("%d", &a);
        if (a == 1)
        {
            scanf("%d", &b);
            ll ans = 0;
            for (auto i : G[b])
                ans += n - cnt[i];
            printf("%lld\n", ans);
        }
        else if (a == 2)
        {
            scanf("%d%d\n", &b, &c);
            G[b].push_back(c);
            ++cnt[c];
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