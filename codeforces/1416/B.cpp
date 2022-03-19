#include <bits/stdc++.h>
using namespace std;
const int N = 1e4 + 5;
int a[N];
vector<pair<pair<int, int>, int>> ans;
void solve()
{
    int n, sum = 0;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d", &a[i]);
        sum += a[i];
    }
    if (sum % n)
        return void(printf("-1\n"));
    int res = sum / n;
    for (int i = 2; i <= n; ++i)
    {
        if (a[i] % i)
        {
            int tmp = i - a[i] % i;
            a[1] -= tmp, a[i] += tmp;
            ans.push_back({{1, i}, tmp});
        }
        a[1] += a[i];
        ans.push_back({{i, 1}, a[i] / i});
        a[i] = 0;
    }
    for (int i = 2; i <= n; ++i)
        ans.push_back({{1, i}, res});
    printf("%d\n", ans.size());
    for (auto &i : ans)
        printf("%d %d %d\n", i.first.first, i.first.second, i.second);
    ans.clear();
}
int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
        solve();
    return 0;
}