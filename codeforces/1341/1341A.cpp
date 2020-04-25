#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5 + 5;
void solve()
{
    int n;
    scanf("%d", &n);
    int a, b, c, d;
    scanf("%d%d%d%d", &a, &b, &c, &d);
    if (n * (a - b) > c + d || n * (a + b) < c - d)
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