#include <algorithm>
#include <cstring>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
struct node {
    int to, cost;
    node(int a, int b)
    {
        to = a, cost = b;
    }
    bool operator<(const node& a) const
    {
        return this->cost > a.cost;
    }
};
int dis[1005], vis[1005], ans[1005];
vector<node> E[1005], TE[1005];
void dij(int n, int x, vector<node>* E)
{
    memset(dis, 0x3f3f3f3f, sizeof(dis));
    memset(vis, 0, sizeof(vis));
    priority_queue<node> que;
    dis[x] = 0;
    que.push(node(x, dis[x]));
    while (!que.empty()) {
        int u = que.top().to;
        que.pop();
        if (vis[u])
            continue;
        vis[u] = 1;
        for (int i = 0; i < E[u].size(); ++i) {
            int v = E[u][i].to, cost = E[u][i].cost;
            if (!vis[v] && dis[v] > dis[u] + cost) {
                dis[v] = dis[u] + cost;
                que.push(node(v, dis[v]));
            }
        }
    }
    dis[1];
}
int main()
{
    int n, m, x, a, b, c;
    cin >> n >> m >> x;
    for (int i = 0; i < m; ++i) {
        cin >> a >> b >> c;
        E[a].push_back(node(b, c));
        TE[b].push_back(node(a, c));
    }
    dij(n, x, E);
    memcpy(ans, dis, sizeof(dis));
    dij(n, x, TE);
    for (int i = 1; i <= n; ++i)
        ans[i] += dis[i];
    cout << *max_element(ans + 1, ans + n + 1) << endl;
    return 0;
}
