#include <bits/stdc++.h>
using namespace std;
const int N = 2.5e5 + 5;
typedef long long ll;
struct stone
{
    ll m, p, r, d;
};
stone st[N];
const int M = 6e2 + 5;
int bg[M], ed[M];
ll maxdis[M];
bool cmpd(const stone &a, const stone &b)
{
    return a.d < b.d;
}
bool cmpm(const stone &a, const stone &b)
{
    return a.m < b.m;
}
bool vis[N];
int main()
{
    int n;
    ll sx, sy;
    st[0].m = 1e18, st[0].d = 0;
    scanf("%lld%lld%lld%lld%d", &sx, &sy, &st[0].p, &st[0].r, &n);
    st[0].r *= st[0].r;
    for (int i = 1; i <= n; ++i)
    {
        ll x, y;
        scanf("%lld%lld%lld%lld%lld", &x, &y, &st[i].m, &st[i].p, &st[i].r);
        st[i].d = 1ll * (sx - x) * (sx - x) + 1ll * (sy - y) * (sy - y);
        st[i].r *= st[i].r;
    }
    sort(st + 1, st + n + 1, cmpd);
    int t = sqrt(n), len = n / t;
    for (int i = 1; i <= t; ++i)
        bg[i] = (i - 1) * len + 1, ed[i] = i * len;
    if (ed[t] < n)
        bg[t + 1] = ed[t] + 1, ed[++t] = n;
    for (int i = 1; i <= t; ++i)
    {
        maxdis[i] = st[ed[i]].d;
        sort(st + bg[i], st + ed[i] + 1, cmpm);
    }
    int ans = -1;
    queue<int> q;
    q.push(0);
    while (q.size())
    {
        int tmp = q.front();
        q.pop();
        ll p = st[tmp].p, r = st[tmp].r;
        ++ans;
        for (int i = 1; i <= t; ++i)
        {
            if (maxdis[i] <= r)
            {
                int j;
                for (j = bg[i]; j <= ed[i] && st[j].m <= p; ++j)
                    if (!vis[j])
                        q.push(j), vis[j] = 1;
                bg[i] = j;
            }
            else
            {
                for (int j = bg[i]; j <= ed[i]; ++j)
                    if (!vis[j] && st[j].m <= p && st[j].d <= r)
                        q.push(j), vis[j] = 1;
                break;
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}