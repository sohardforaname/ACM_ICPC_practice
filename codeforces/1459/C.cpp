#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5 + 5;
ll a[N], b[N];
int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i)
        scanf("%lld", a + i);
    for (int i = 1; i <= m; ++i)
        scanf("%lld", b + i);
    ll gcd1 = 0ll;
    for (int i = 2; i <= n; ++i)
        gcd1 = gcd(gcd1, a[i] - a[i - 1]);
    for (int i = 1; i <= m; ++i)
        printf("%lld%c", gcd(a[1] + b[i], gcd1), " \n"[i == m]);
    return 0;
}