#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
vector<int> d[N];
vector<int> lp;
int c[N], p[N];
bool vis[N];
int cyc;
void solve()
{
    int n;
    scanf("%d", &n);
    memset(vis, 0, sizeof(vis[0]) * (n + 1));
    for (int i = 1; i <= n; ++i)
        scanf("%d", &p[i]);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &c[i]);
    int minn = N;
    for (int i = 1; i <= n; ++i)
    {
        lp.clear();
        int cur = i;
        while (!vis[cur])
        {
            vis[cur] = 1;
            lp.push_back(cur);
            cur = p[cur];
        }
        for (auto len : d[lp.size()])
            for (int i = 0; i < len; ++i)
            {
                bool f = 1;
                for (int j = i; j < lp.size(); j += len)
                    if (c[lp[j]] != c[lp[i]])
                    {
                        f = 0;
                        break;
                    }
                if (f)
                {
                    minn = min(minn, len);
                    break;
                }
            }
    }
    printf("%d\n", minn);
}
int main()
{
    for (int i = 1; i < N; ++i)
        for (int j = i; j < N; j += i)
            d[j].push_back(i);
    int T;
    scanf("%d", &T);
    while (T--)
        solve();
    return 0;
}