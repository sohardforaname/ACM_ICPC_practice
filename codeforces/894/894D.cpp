#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 9;
typedef long long ll;
int len[N];
vector<ll> dis[N];
vector<ll> sum[N];
int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 2; i <= n; ++i)
        scanf("%d", &len[i]);
    for (int i = n; i; --i)
    {
        int tmp = i;
        ll l = 0;
        while (tmp)
        {
            dis[tmp].push_back(l);
            l += len[tmp];
            tmp /= 2;
        }
        sort(dis[i].begin(), dis[i].end());
        ll t = 0;
        for (auto j : dis[i])
            sum[i].push_back((t += j));
    }
    for (int i = 1; i <= m; ++i)
    {
        int a, h;
        scanf("%d%d", &a, &h);
        ll ans = 0, tmpl = 0;
        int pre = 0;
        while (a && tmpl < h)
        {
            int pos = upper_bound(dis[a].begin(), dis[a].end(), h - tmpl) - dis[a].begin();
            if (pos)
                ans += (h - tmpl) * pos - sum[a][pos - 1];
            if (pre)
            {
                pos = upper_bound(dis[pre].begin(), dis[pre].end(), h - tmpl - len[pre]) - dis[pre].begin();
                if (pos)
                    ans -= (h - tmpl - len[pre]) * pos - sum[pre][pos - 1];
            }
            tmpl += len[a];
            pre = a;
            a /= 2;
        }
        printf("%lld\n", ans);
    }
    return 0;
}