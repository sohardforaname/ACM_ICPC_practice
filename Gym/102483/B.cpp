#include <bits/stdc++.h>
using namespace std;
const int N = 4e5 + 5;
vector<int> G[N];
int dp[N], w[N], in[N];
struct cmp
{
    bool operator()(const int &a, const int &b)
    {
        return w[a] > w[b];
    }
};
int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
    {
        int m;
        scanf("%d%d", &w[i], &m);
        for (int j = 1; j <= m; ++j)
        {
            int v;
            scanf("%d", &v);
            G[i].push_back(v);
            ++in[v];
        }
    }
    int t = n - 1;
    priority_queue<int, vector<int>, cmp> q;
    for (int i = 1; i <= n; ++i)
        if (!in[i])
            q.push(i);
    int maxn = 0;
    while (q.size())
    {
        int cur = q.top();
        q.pop();
        maxn = max(maxn, w[cur] + t);
        --t;
        for (auto i : G[cur])
        {
            --in[i];
            if (!in[i])
                q.push(i);
        }
    }
    printf("%d\n", maxn);
    return 0;
}