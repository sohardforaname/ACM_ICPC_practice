#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int a, b;
    scanf("%d%d", &a, &b);
    int ans = 0;
    for (int i = 0; i <= 31; ++i)
        if ((a >> i & 1) && (b >> i & 1))
            ans ^= 1 << i;
    printf("%d\n", (ans ^ a) + (ans ^ b));
}
int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
        solve();
    return 0;
}