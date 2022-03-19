#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int n, a;
    scanf("%d", &n);
    int minpos = 0;
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d", &a);
        if (!minpos && a != 1)
            minpos = i;
    }
    if (!minpos)
        minpos = n;
    printf("%s", minpos % 2 ? "First\n" : "Second\n");
}
int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
        solve();
    return 0;
}