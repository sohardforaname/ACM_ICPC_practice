#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 5, M = 1e1 + 5;
typedef long long ll;
int a[M];
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
int main()
{
    ll l, r;
    scanf("%d%lld%lld", &n, &l, &r);
    for (int i = 1; i <= n; ++i)
        scanf("%d", a + i);
    bfs();
    ll ans = 0;
    for (int i = 0; i < a[1]; ++i)
        if (vis[i])
        {
            ll d = k[i] * a[1] + i;
            if (r >= d)
                ans += (r - d) / a[1] + 1;
            if (l - 1 >= d)
                ans -= (l - 1 - d) / a[1] + 1;
        }
    printf("%lld\n", ans);
    return 0;
}