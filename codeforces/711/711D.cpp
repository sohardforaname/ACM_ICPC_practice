#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5 + 5;
const ll mod = 1e9 + 7;
typedef long long ll;
ll pow(ll a, ll b, ll p)
{
    ll res = 1;
    while (b)
    {
        if (b & 1)
            res = res * a % p;
        a = a * a % p;
        b >>= 1;
    }
    return res;
}
vector<int> G[N];
int c[N], cyc[N];
bool vis[N];
void bfs(int u, int t)
{
    queue<int> q;
    q.push(u);
    while (q.size())
    {
        int cur = q.front();
        q.pop();
        if (vis[cur])
            continue;
        vis[cur] = 1;
        ++c[t];
        for (auto i : G[cur])
            q.push(i);
    }
}
int in[N], n;
void topo()
{
    queue<int> q;
    for (int i = 1; i <= n; ++i)
        if (in[i] == 1)
            q.push(i);
    while (q.size())
    {
        int cur = q.front();
        q.pop();
        for (auto i : G[cur])
            if (in[i] > 1 && (--in[i] == 1))
                q.push(i);
    }
}
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
    {
        int v;
        scanf("%d", &v);
        G[v].push_back(i);
        G[i].push_back(v);
        ++in[i], ++in[v];
    }
    int t = 0;
    for (int i = 1; i <= n; ++i)
        if (!vis[i])
            bfs(i, ++t);
    topo();
    ll ans = 1, ctot = 0;
    for (int i = 1; i <= n; ++i)
        if (in[i] > 1)
        {
            int v = i;
            ll cn = 0;
            while (in[v] > 1)
            {
                in[v] = 1;
                ++cn;
                for (auto j : G[v])
                    if (in[j] > 1)
                    {
                        v = j;
                        break;
                    }
            }
            ctot += cn;
            ans = ans * (pow(2, cn, mod) - 2 + mod) % mod;
        }
    ans = ans * pow(2, n - ctot, mod) % mod;
    printf("%lld\n", ans);
    return 0;
}