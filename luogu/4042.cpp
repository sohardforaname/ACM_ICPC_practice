#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5 + 5;
vector<int> G[N];
ll k[N], s[N];
int r[N];
ll dp[N];

struct node
{
    int to;
    ll w;
    bool operator<(const node &n) const
    {
        return w > n.w;
    }
};
int n;
bool vis[N];
ll dis[N];

void cal()
{
    priority_queue<node> q;
    for (int i = 1; i <= n; ++i)
        q.push({i, k[i]}), dp[i] = s[i];
    while (q.size())
    {
        auto nde = q.top();
        q.pop();
        if (vis[nde.to])
            continue;
        vis[nde.to] = 1;
        dis[nde.to] = nde.w;
        for (auto i : G[nde.to])
        {
            if (vis[i] || dp[i] > k[i])
                continue;
            dp[i] += dis[nde.to];
            --r[i];
            if (!r[i])
                q.push({i, dp[i]});
        }
    }
}

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
    {
        int x;
        scanf("%lld%lld%d", s + i, k + i, r + i);
        for (int j = 1; j <= r[i]; ++j)
        {
            scanf("%d", &x);
            G[x].push_back(i);
        }
    }
    cal();
    printf("%lld\n", dis[1]);
    return 0;
}
