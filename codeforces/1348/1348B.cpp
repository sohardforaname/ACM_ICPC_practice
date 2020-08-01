#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5 + 5;
set<int> s;
int a[N], b[N];
void solve()
{
    s.clear();
    int n, k;
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d", &a[i]);
        s.insert(a[i]);
    }
    if (s.size() > k)
    {
        printf("-1\n");
        return;
    }
    int pos = 1, top = 0;
    while (pos <= n)
    {
        auto it = s.begin(), eit = --s.end();
        for (int i = 1; i <= k && pos <= n; ++i)
        {
            b[++top] = *it;
            if (*it == a[pos])
                ++pos;
            if (it != eit)
                ++it;
        }
    }
    printf("%d\n", top);
    for (int i = 1; i <= top; ++i)
        printf("%d%c", b[i], " \n"[i == top]);
}
int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
        solve();
    return 0;
}