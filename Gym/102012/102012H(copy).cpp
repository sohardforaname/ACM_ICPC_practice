#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
pair<pair<int, int>, int> a[N], p[N << 1];
int ans[N], vis[N], c[N];
void solve()
{
    int n, k;
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; ++i)
        scanf("%d%d", &a[i].first.first, &a[i].first.second);
    if (n < k)
    {
        printf("0\n");
        for (int i = 1; i <= n; ++i)
            printf("%d%c", 1, " \n"[i == n]);
        return;
    }
    for (int i = 1; i <= n; ++i)
        a[i].second = i;
    sort(a + 1, a + n + 1);
    priority_queue<pair<int, int>> q;
    for (int i = 1; i <= k; ++i)
        q.push({0, i});
    for (int i = 1; i <= n; ++i)
    {
        int col = q.top().second;
        q.pop();
        ans[a[i].second] = c[i] = col;
        q.emplace(-a[i].first.second, col);
    }
    int top = 0;
    for (int i = 1; i <= n; ++i)
    {
        p[++top] = make_pair(make_pair(a[i].first.first, c[i]), 1);
        p[++top] = make_pair(make_pair(a[i].first.second, c[i]), -1);
    }
    sort(p + 1, p + top + 1);
    int res = 0, cur = 0;
    for (int i = 1; i <= top; ++i)
    {
        if (vis[p[i].first.second])
            --cur;
        vis[p[i].first.second] += p[i].second;
        if (vis[p[i].first.second])
            ++cur;
        if (cur == k)
            res += p[i + 1].first.first - p[i].first.first;
    }
    printf("%d\n", res);
    for (int i = 1; i <= n; ++i)
        printf("%d%c", ans[i], " \n"[i == n]);
}
int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
        solve();
    return 0;
}