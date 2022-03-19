#include <bits/stdc++.h>
using namespace std;
const int N = 3e3 + 5;
typedef long long ll;
int a[N];
bool vis[N];
ll k[N];

int n;
void bfs()
{
    sort(a + 1, a + n + 1, greater<int>());
    memset(k, 0x3f, sizeof(k));
    k[0] = 0;
    deque<int> q;
    q.emplace_back(0);
    while (q.size())
    {
        int x = q.front();
        q.pop_front();
        if (vis[x])
            continue;
        vis[x] = 1;
        for (int i = 2; i <= n; ++i)
        {
            if (x + a[i] < a[1])
            {
                k[x + a[i]] = min(k[x + a[i]], k[x]);
                q.emplace_front(x + a[i]);
            }
            else
            {
                int v = (x + a[i]) % a[1];
                k[v] = min(k[v], k[x] + 1);
                q.emplace_back(v);
            }
        }
    }
}
int l[N];
bool use[N];
ll dis[N];
int main()
{
    int t, m;
    scanf("%d%d", &t, &m);
    for (int i = 1; i <= t; ++i)
        scanf("%d", l + i);
    sort(l + 1, l + t + 1);
    for (int i = 1; i <= t; ++i)
        for (int j = max(1, l[i] - m); j <= l[i]; ++j)
            if (!use[j])
                use[j] = 1, a[++n] = j;
    bfs();
    ll ans = 0;
    for (int i = 0; i < a[1]; ++i)
    {
        if (!vis[i])
            return printf("-1\n"), 0;
        ll d = a[1] * k[i] + i;
        dis[i] = d;
        ans = max(ans, d);
    }
    printf("%lld\n", ans - a[1]);
    return 0;
}