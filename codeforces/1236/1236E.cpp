#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
typedef long long ll;
int a[N], l[N << 2], r[N << 2];
const int offset = 1e5;
int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; ++i)
        scanf("%d", &a[i]);
    if (n == 1)
        return printf("0\n"), 0;
    for (int i = m; i >= 1; --i)
    {
        l[a[i] - i + offset] = l[a[i] - i - 1 + offset] + 1;
        r[a[i] + i + offset] = r[a[i] + i + 1 + offset] + 1;
    }
    ll ans = 0;
    for (int i = 1; i <= n; ++i)
    {
        int rr = min(n, i + m + 1 - l[i + offset]);
        int ll = max(1, i - m - 1 + r[i + offset]);
        ans += rr - ll + 1;
    }
    printf("%lld\n", ans);
    return 0;
}