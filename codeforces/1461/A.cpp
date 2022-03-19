#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5 + 5;
void solve()
{
    int n, k;
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= k; ++i)
        putchar('a');
    int tag = 1;
    for (int i = k + 1; i <= n; ++i)
        putchar('a' + tag), tag = (tag + 1) % 3;
    putchar('\n');
}
int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
        solve();
    return 0;
}