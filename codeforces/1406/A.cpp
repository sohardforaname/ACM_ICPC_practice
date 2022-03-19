#include <bits/stdc++.h>
using namespace std;
const int N = 1e2 + 5;
int buc[N];
void solve()
{
    memset(buc, 0, sizeof(buc));
    int n, a;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d", &a);
        ++buc[a];
    }
    int pos1 = 0;
    for (; pos1 < N; ++pos1)
        if (buc[pos1] < 2)
            break;
    int pos2 = pos1;
    for (; pos2 < N; ++pos2)
        if (buc[pos2] < 1)
            break;
    printf("%d\n", pos1 + pos2);
}
int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
        solve();
    return 0;
}