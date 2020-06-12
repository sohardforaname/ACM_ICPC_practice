#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
set<int> s;
void solve()
{
    s.clear();
    int n, a;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d", &a);
        s.insert(a);
    }
    set<int> t;
    int maxn = *(--s.end());
    int ans = -1;
    for (int i = 1; i < (1 << 10); ++i)
    {
        t.clear();
        for (auto &j : s)
            t.insert(i ^ j);
        if (s == t)
        {
            ans = i;
            break;
        }
    }
    printf("%d\n", ans);
}
int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
        solve();
    return 0;
}