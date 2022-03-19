#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
typedef long long ll;
ll a[N], n, sumn, sump, a1;
void upd(int pos, int val)
{
    if (pos > n)
        return;
    a[pos] > 0 ? sump -= a[pos] : sumn += a[pos];
    a[pos] += val;
    a[pos] > 0 ? sump += a[pos] : sumn -= a[pos];
}
void solve()
{
    scanf("%lld", &n);
    for (int i = 1; i <= n; ++i)
        scanf("%lld", &a[i]);
    for (int i = 2; i <= n; ++i)
    {
        sump += max(0ll, a[i] - a[i - 1]);
        sumn -= min(0ll, a[i] - a[i - 1]);
    }
    for (int i = n; i; --i)
        a[i] = a[i] - a[i - 1];
    a1 = a[1];
    printf("%lld\n", (ll)ceil((a1 + sump) / 2.0));
    int q;
    scanf("%d", &q);
    for (int i = 1; i <= q; ++i)
    {
        int l, r, x;
        scanf("%d%d%d", &l, &r, &x);
        if (l == 1)
            a1 += x;
        else
            upd(l, x);
        upd(r + 1, -x);
        printf("%lld\n", (ll)ceil((a1 + sump) / 2.0));
    }
}
int main()
{
    int T = 1;
    //scanf("%d", &T);
    while (T--)
        solve();
    return 0;
}