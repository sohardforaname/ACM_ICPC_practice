#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5 + 5;
void solve()
{
    int n, x, a;
    scanf("%d%d", &n, &x);
    int odd = 0;
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d", &a);
        if (a % 2)
            ++odd;
    }
    int even = n - odd;
    if (!odd)
        printf("No\n");
    else if (x == n && odd % 2 == 0)
        printf("No\n");
    else if (!even && x % 2 == 0)
        printf("No\n");
    else
        printf("Yes\n");
}
int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
        solve();
    return 0;
}