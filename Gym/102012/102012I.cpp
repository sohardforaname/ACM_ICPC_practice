#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e1 + 5;
ll ans;
vector<int> tmp;
vector<int> vec;
int u[N], v[N];
ll dfs(vector<int> &vec, int cur)
{
    if (cur < 0)
        return 1;
    ll ans = 0;
    if (vec[u[cur]] < vec[v[cur]])
    {
        ans += dfs(vec, cur - 1);
        swap(vec[u[cur]], vec[v[cur]]);
        ans += dfs(vec, cur - 1);
        swap(vec[u[cur]], vec[v[cur]]);
    }
    return ans;
}
set<vector<int>> s;
void solve()
{
    s.clear();
    ans = 0;
    int n, m;
    ll mod;
    scanf("%d%d%lld", &n, &m, &mod);
    for (int i = 0; i < m; ++i)
    {
        scanf("%d%d", &u[i], &v[i]);
        --u[i], --v[i];
    }
    for (int i = 0; i < n; ++i)
    {
        tmp.clear();
        for (int j = 0; j < i; ++j)
            tmp.push_back(j);
        for (int j = i + 1; j < n; ++j)
            tmp.push_back(j);
        //i一定不在tmp里
        for (int j = 0; j < n; ++j)
        {
            vec.clear();
            for (int k = 0; k < j; ++k)
                vec.push_back(tmp[k]);
            vec.push_back(i);
            for (int k = j; k < tmp.size(); ++k)
                vec.push_back(tmp[k]);
            if (s.find(vec) == s.end())
                ans += dfs(vec, m - 1), s.insert(vec);
        }
    }
    printf("%lld\n", ans % mod);
}
int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
        solve();
    return 0;
}