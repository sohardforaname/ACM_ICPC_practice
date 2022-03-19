#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
typedef long long ll;
int a[N];
int main()
{
    int n, k;
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &a[i]);
    sort(a + 1, a + n + 1);
    if (!k)
        return printf("%d\n", a[n] - a[1]), 0;
    ll sum = 0;
    for (int i = n, t = 1; i >= 1 && t <= k; --i, ++t)
        sum += a[i];
    return printf("%lld\n", sum + a[n - k]), 0;
}