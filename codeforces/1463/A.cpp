#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    if ((a + b + c) % 9)
        return void(printf("NO\n"));
    int q = (a + b + c) / 9;
    if (a < q || b < q || c < q)
        return void(printf("NO\n"));
    printf("YES\n");
}
int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
        solve();
    return 0;
}