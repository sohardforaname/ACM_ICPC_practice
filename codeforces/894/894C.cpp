#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 5;
int a[N];
int gcd(int a, int b)
{
    return !b ? a : gcd(b, a % b);
}
int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &a[i]);
    int sum = a[1];
    for (int i = 2; i <= n; ++i)
        sum = gcd(sum, a[i]);
    if (sum != a[1])
        return printf("-1\n"), 0;
    printf("%d\n", n << 1);
    for (int i = 1; i <= n; ++i)
        printf("%d %d%c", a[1], a[i], " \n"[i == n]);
    return 0;
}