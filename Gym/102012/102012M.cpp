#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e3 + 5;
struct point
{
    ll x, y;
    point(ll _x, ll _y) : x(_x), y(_y) {}
    point() {}
    point operator-(const point &a) const
    {
        return point(x - a.x, y - a.y);
    }
    ll dot(const point &a)
    {
        return x * a.x + y * a.y;
    }
    ll det(const point &a)
    {
        return x * a.y - y * a.x;
    }
};
point p[N], li[N];
int l[N], r[N], add[N], id[N];
int n, m;
void init()
{
    scanf("%d%d", &n, &m);
    memset(l, 0, sizeof(l[0]) * (m + 1));
    memset(r, 0, sizeof(r[0]) * (m + 1));
    memset(add, 0, sizeof(add[0]) * (n + 1));
    memset(id, 0, sizeof(id[0]) * (n + 1));
    for (int i = 0; i < n; ++i)
        scanf("%lld%lld", &p[i].x, &p[i].y);
    for (int i = 0; i < m; ++i)
        scanf("%lld%lld", &li[i].x, &li[i].y);
    for (int i = 0; i < m; ++i)
    {
        for (int j = 1; j < n; ++j)
        {
            if ((p[l[i]] - li[i]).det(p[j] - li[i]) > 0)
                l[i] = j;
            if ((p[r[i]] - li[i]).det(p[j] - li[i]) < 0)
                r[i] = j;
        }
        int len = (r[i] - l[i] + n) % n;
        for (int j = 0; j < len; ++j)
        {
            int cur = (l[i] + j) % n;
            int maxl = (r[i] - cur + n) % n;
            if (maxl > add[cur])
                add[cur] = maxl, id[cur] = i;
        }
    }
}
vector<int> ans, tmp;
void solve()
{
    init();
    ans.clear();
    int maxn = 1e5;
    for (int i = 0; i < n; ++i)
    {
        int pos = i, cnt = 0, lft = n;
        tmp.clear();
        while (lft > 0)
        {
            if (add[pos] == 0)
            {
                cnt = 1e5;
                break;
            }
            lft -= add[pos];
            tmp.push_back(id[pos]);
            pos = (pos + add[pos]) % n;
            ++cnt;
        }
        if (cnt < maxn)
        {
            maxn = cnt;
            ans = tmp;
        }
    }
    if (maxn == 1e5)
    {
        printf("-1\n");
        return;
    }
    else
    {
        printf("%d\n", ans.size());
        for (int i = 0; i < ans.size(); ++i)
            printf("%d%c", ans[i] + 1, " \n"[i == ans.size() - 1]);
        return;
    }
}
int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
        solve();
    return 0;
}