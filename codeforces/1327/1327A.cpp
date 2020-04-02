#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int n, k;
    scanf("%d%d", &n, &k);
    long long sum = 0;
    sum = (1 + k * 2ll - 1) * k / 2;
    if (sum > n)
        printf("NO\n");
    else if ((n - sum) % 2)
        printf("NO\n");
    else
        printf("YES\n");
}
int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
        solve();
    return 0;
}