#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
typedef long long ll;
ll a[N];
int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        scanf("%lld", &a[i]);
    if (n == 1)
        return printf("1 1\n0\n 1 1\n0\n 1 1\n%lld\n", -a[1]), 0;
    printf("1 1\n%lld\n", -a[1]);
    printf("1 %d\n0 ", n);
    for (int i = 2; i <= n; ++i)
        printf("%lld%c", -n * a[i], " \n"[i == n]);
    printf("2 %d\n", n);
    for (int i = 2; i <= n; ++i)
        printf("%lld%c", (n - 1) * a[i], " \n"[i == n]);
    return 0;
}
