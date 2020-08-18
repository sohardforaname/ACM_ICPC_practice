#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
typedef long long ll;
ll a[N];
int f[N], in[N];
vector<int> G[N];
queue<int> q, s1;
stack<int> s2;
bool vis[N];
int n;
void toposort()
{
    for (int i = 1; i <= n; ++i)
        if (in[i] == 0)
            q.push(i);
    while (q.size())
    {
        int cur = q.front();
        q.pop();
        if (a[cur] > 0)
        {
            s1.push(cur);
            if (f[cur] != -1)
                a[f[cur]] += a[cur];
            vis[cur] = 1;
        }
        else
            s2.push(cur);
        if (f[cur] != -1)
        {
            --in[f[cur]];
            if (!in[f[cur]])
                q.push(f[cur]);
        }
    }
}
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        scanf("%lld", &a[i]);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &f[i]);
    for (int i = 1; i <= n; ++i)
        if (f[i] != -1)
        {
            G[i].push_back(f[i]);
            ++in[f[i]];
        }
    toposort();
    ll ans = 0;
    for (int i = 1; i <= n; ++i)
        ans += a[i];
    printf("%lld\n", ans);
    while (s1.size())
    {
        printf("%d ", s1.front());
        s1.pop();
    }
    while (s2.size())
    {
        printf("%d ", s2.top());
        s2.pop();
    }
    printf("\n");
    return 0;
}