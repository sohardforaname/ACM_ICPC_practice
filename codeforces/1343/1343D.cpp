#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
int a[N];
int d[N << 1];
void solve()
{
    int n, k;
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &a[i]);
    memset(d, 0, sizeof(d[0]) * (2 * k + 10));
    for (int i = 1; i <= n / 2; ++i)
    {
        int sum = a[i] + a[n - i + 1];
        int maxn = max(a[i], a[n - i + 1]);
        int minn = min(a[i], a[n - i + 1]);
        d[2] += 2, d[minn + 1] -= 2;
        d[maxn + k + 1] += 2, d[2 * k + 1] -= 2;
        d[minn + 1] += 1, d[maxn + k + 1] -= 1;
        d[sum] -= 1, d[sum + 1] += 1;
    }
    int minn = n;
    for (int i = 2; i <= 2 * k; ++i)
    {
        d[i] += d[i - 1];
        minn = min(minn, d[i]);
    }
    printf("%d\n", minn);
}
int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
        solve();
    return 0;
}