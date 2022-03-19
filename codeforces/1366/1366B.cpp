#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
typedef long long ll;
typedef pair<int, int> pii;
void solve()
{
    int n, x, m;
    scanf("%d%d%d", &n, &x, &m);
    int ql, qr, l, r;
    ql = qr = x;
    for (int i = 1; i <= m; ++i)
    {
        scanf("%d%d", &l, &r);
        if (ql > r || qr < l)
            continue;
        ql = min(ql, l);
        qr = max(qr, r);
    }
    printf("%d\n", qr - ql + 1);
}
int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
        solve();
    return 0;
}