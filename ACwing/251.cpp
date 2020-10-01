#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 5e4 + 5;
struct seg
{
    int l, r, id;
};
seg s[N];
bool cmpl(const seg &a, const seg &b)
{
    return a.l < b.l;
}
bool cmpr(const seg &a, const seg &b)
{
    return a.r < b.r;
}
ll gcd(ll a, ll b)
{
    return !b ? a : gcd(b, a % b);
}
const int M = 3e2 + 5;
int bg[M], ed[M], c[N];
ll num[N], tot;
void upd(int pos, int v)
{
    tot += (num[c[pos]] << 1) * v + 1;
    num[c[pos]] += v;
}
pair<ll, ll> ans[N];
int main()
{
    int n, q;
    scanf("%d%d", &n, &q);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &c[i]);
    for (int i = 1; i <= q; ++i)
        scanf("%d%d", &s[i].l, &s[i].r), s[i].id = i;
    sort(s + 1, s + q + 1, cmpl);
    int t = sqrt(q), len = q / t;
    for (int i = 1; i <= t; ++i)
        bg[i] = (i - 1) * len + 1, ed[i] = i * len;
    if (ed[t] < q)
        bg[t + 1] = ed[t] + 1, ed[++t] = q;
    for (int i = 1; i <= t; ++i)
        sort(s + bg[i], s + ed[i] + 1, cmpr);
    for (int i = 1, l = 1, r = 0; i <= q; ++i)
    {
        while (l < s[i].l)
            upd(l++, -1);
        while (l > s[i].l)
            upd(--l, 1);
        while (r < s[i].r)
            upd(++r, 1);
        while (r > s[i].r)
            upd(r--, -1);
        int x = s[i].id;
        len = s[i].r - s[i].l + 1;
        ans[x].first = tot - len;
        ans[x].second = (len - 1ll) * len;
    }
    for (int i = 1; i <= q; ++i)
    {
        ll g = gcd(ans[i].first, ans[i].second);
        printf("%lld/%lld\n", ans[i].first / g, ans[i].second / g);
    }
    return 0;
}
