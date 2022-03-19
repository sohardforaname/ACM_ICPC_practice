#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 5;
vector<int> G[N];
int size[N], n;
typedef long long ll;
ll ans;
void dfs(int u)
{
    size[u] = 1;
    for (auto i : G[u])
    {
        dfs(i);
        size[u] += size[i];
    }
}
int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        int n;
        scanf("%d", &n);
        for (int i = 1; i <= n; ++i)
            G[i].clear();
        ans = 0;
        for (int i = 2; i <= n; ++i)
        {
            int f;
            scanf("%d", &f);
            G[f].push_back(i);
        }
        dfs(1);
        printf("%lld\n", ans);
    }
    return 0;
}