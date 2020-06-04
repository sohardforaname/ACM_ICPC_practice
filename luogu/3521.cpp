#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
typedef long long ll;
struct node
{
    int sum, l, r;
};
node tr[N * 20];
int cnt;
ll ans1, ans2;
void update(int &rt, int l, int r, int v)
{
    if (!rt)
        rt = ++cnt;
    ++tr[rt].sum;
    if (l == r)
        return;
    int m = (l + r) >> 1;
    if (v <= m)
        update(tr[rt].l, l, m, v);
    else if (v > m)
        update(tr[rt].r, m + 1, r, v);
}
void merge(int &lt, int rt)
{
    if (!rt || !lt)
    {
        lt += rt;
        return;
    }
    tr[lt].sum += tr[rt].sum;
    ans1 += (ll)tr[tr[lt].l].sum * tr[tr[rt].r].sum; //顺序
    ans2 += (ll)tr[tr[lt].r].sum * tr[tr[rt].l].sum; //逆序
    merge(tr[lt].l, tr[rt].l);
    merge(tr[lt].r, tr[rt].r);
}
int t, n;
ll ans;
void solve(int &u)
{
    int lt, rt;
    u = 0;
    scanf("%d", &t);
    if (!t)
    {
        solve(lt);
        solve(rt);
        u = lt;
        ans1 = ans2 = 0;
        merge(u, rt);
        ans += min(ans1, ans2);
    }
    else
        update(u, 1, n, t);
}
int main()
{
    scanf("%d", &n);
    int t = 0;
    solve(t);
    printf("%lld\n", ans);
    return 0;
}