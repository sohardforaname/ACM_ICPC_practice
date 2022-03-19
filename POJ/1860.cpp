#include <algorithm>
#include <cstring>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
struct node {
    int to;
    double rate, cost;
    node(int a, double b, double c)
    {
        to = a, rate = b, cost = c;
    }
};
vector<node> E[105];
int vis[105], inque[105];
double dis[105];
bool spfa(int n, double cur, int k)
{
    memset(inque, 0, sizeof(inque));
    memset(vis, 0, sizeof(vis));
    for (int i = 1; i <= n; ++i)
        dis[i] = 0;
    queue<int> que;
    que.push(k);
    vis[k] = 1;
    ++inque[k];
    dis[k] = cur;
    while (!que.empty()) {
        int u = que.front(); //出队
        que.pop();
        vis[u] = 0; //取消标记
        for (int i = 0; i < E[u].size(); ++i) {
            int v = E[u][i].to;
            double tmp = (dis[u] - E[u][i].cost) * E[u][i].rate;
            if (dis[v] < tmp) {
                dis[v] = tmp; //松弛
                if (!vis[v]) {
                    que.push(v);
                    vis[v] = 1;
                    ++inque[v];
                }
                if (inque[v] > n)
                    return 1;
            }
        }
    }
    return 0;
}
int main()
{
    int n, m, k, g, h;
    double a, b, c, d, cur;
    cin >> n >> m >> k >> cur;
    for (int i = 0; i < m; ++i) {
        cin >> g >> h >> a >> b >> c >> d;
        E[g].push_back(node(h, a, b));
        E[h].push_back(node(g, c, d));
    }
    if (spfa(n, cur, k))
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
    return 0;
}