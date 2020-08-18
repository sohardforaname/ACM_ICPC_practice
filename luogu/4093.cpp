#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
struct BIT
{
    int c[N << 1];
    int lowbit(int x)
    {
        return x & (-x);
    }
    void update(int x, int n, int val, int f)
    {
        for (; x <= n; x += lowbit(x))
        {
            if (f)
                c[x] = max(c[x], val);
            else
                c[x] = 0;
        }
    }
    int query(int x)
    {
        int ans = 0;
        for (; x; x -= lowbit(x))
            ans = max(ans, c[x]);
        return ans;
    }
};
int q[N], q1[N], minn[N], maxn[N], val[N];
int dp[N];
bool cmpval(const int &i, const int &j)
{
    return val[i] < val[j];
}
bool cmpminn(const int &i, const int &j)
{
    return minn[i] < minn[j];
}
BIT tr;
int n, m;
void solve(int l, int r)
{
    if (l == r)
        return;
    int m = (l + r) >> 1;
    solve(l, m);
    sort(q + 1, q + m + 1, cmpval);
    sort(q + m + 1, q + r + 1, cmpminn);
    int p1 = l, p2 = m + 1;
    while (p2 <= r)
    {
        while (p1 <= m && minn[q[p2]] >= val[q[p1]])
            tr.update(maxn[q[p1]], n, dp[q[p1]], 1), ++p1;
        dp[q[p2]] = max(dp[q[p2]], tr.query(val[q[p2]]) + 1);
        ++p2;
    }
    for (int i = l; i <= r; ++i)
        q[i] = q1[i];
    for (int i = l; i < p1; ++i)
        tr.update(maxn[q[i]], n, dp[q[i]], 0);
    solve(m + 1, r);
}
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &val[i]), maxn[i] = minn[i] = val[i];
    scanf("%d", &m);
    for (int i = 1; i <= m; ++i)
    {
        int pos, v;
        scanf("%d%d", &pos, &v);
        maxn[pos] = max(maxn[pos], v);
        minn[pos] = min(minn[pos], v);
    }
    for (int i = 1; i <= n; ++i)
        q[i] = q1[i] = i, dp[i] = 1;
    solve(1, n);
    int ans = 0;
    for (int i = 1; i <= n; ++i)
        ans = max(ans, dp[i]);
    printf("%d\n", ans);
    return 0;
}