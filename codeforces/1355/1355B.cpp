#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5 + 5;
int cnt[N];
void solve()
{
    int n, a;
    scanf("%d", &n);
    memset(cnt, 0, sizeof(cnt[0]) * (n + 1));
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d", &a);
        ++cnt[a];
    }
    int ans = 0, rem = 0;
    for (int i = 1; i <= n; ++i)
    {
        ans += (cnt[i] + rem) / i;
        rem = (cnt[i] + rem) % i;
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