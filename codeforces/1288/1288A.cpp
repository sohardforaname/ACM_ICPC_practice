#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
void solve()
{
    int n, d;
    scanf("%d%d", &n, &d);
    for (int i = 0; i * i <= d; ++i)
    {
        int ans = 0;
        if (d % (i + 1))
            ans = d / (i + 1) + 1 + i;
        else
            ans = d / (i + 1) + i;
        if (n >= ans)
        {
            puts("YES");
            return;
        }
    }
    puts("NO");
}
int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
        solve();
    return 0;
}