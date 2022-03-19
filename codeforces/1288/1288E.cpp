#include <bits/stdc++.h>
using namespace std;
const int N = 3e5 + 5;
struct BIT
{
    int c[N << 1];
    void update(int pos, int n, int v)
    {
        for (; pos <= n; pos += pos & (-pos))
            c[pos] += v;
    }
    int query(int pos)
    {
        int res = 0;
        for (; pos; pos -= pos & (-pos))
            res += c[pos];
        return res;
    }
};
BIT tr;
pair<int, int> ans[N];
int pos[N];
void solve()
{
    memset(tr.c, 0, sizeof(tr.c));
    int n, m, a;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i)
        ans[i] = {i, i}, pos[i] = m + i;
    for (int i = m + 1; i <= m + n; ++i)
        tr.update(i, m + n, 1);
    for (int i = 1; i <= m; ++i)
    {
        scanf("%d", &a);
        int p = pos[a];
        ans[a].second = max(ans[a].second, tr.query(p));
        ans[a].first = 1;
        tr.update(p, m + n, -1);
        pos[a] = m + 1 - i;
        tr.update(pos[a], m + n, 1);
    }
    for (int i = 1; i <= n; ++i)
        ans[i].second = max(ans[i].second, tr.query(pos[i]));
    for (int i = 1; i <= n; ++i)
        printf("%d %d\n", ans[i].first, ans[i].second);
}
int main()
{
    int T = 1;
    //scanf("%d", &T);
    while (T--)
        solve();
    return 0;
}