#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5 + 5;
const double INF = 2e18;
struct Node {
    ll x, y;
};
Node a[N], tmp[N];
bool cmp(Node& x, Node& y)
{
    return x.x == y.x ? x.y < y.y : x.x < y.x;
}
ll sqr(ll x)
{
    return x * x;
}
ll dist(int i, int j)
{
    return sqr(a[i].x - a[j].x) + sqr(a[i].y - a[j].y);
}
void merge(int l, int r)
{
    int mid = (l + r) >> 1;
    int i = l, j = mid + 1;
    for (int k = l; k <= r; ++k) {
        if (i > mid || (j <= r && a[j].y < a[i].y))
            tmp[k] = a[j++];
        else
            tmp[k] = a[i++];
    }
    memcpy(a + l, tmp + l, sizeof(Node) * (r - l + 1));
}
int b[N];
ll solve(int l, int r)
{
    if (l >= r)
        return INF;
    if (r - l == 1) {
        if (a[l].y > a[r].y)
            swap(a[l], a[r]);
        return dist(l, r);
    }
    int m = (l + r) >> 1;
    auto d = (ll)INF;
    ll midv = a[m].x;
    d = min(solve(l, m), solve(m + 1, r));
    merge(l, r);
    int top = 0;
    for (int i = l; i <= r; ++i)
        if (sqr(a[i].x - midv) < d)
            b[++top] = i;
    for (int i = 1; i <= top; ++i)
        for (int j = i + 1; j <= top && sqr(a[b[j]].y - a[b[i]].y) < d; ++j)
            d = min(d, dist(b[j], b[i]));
    return d;
}
int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        scanf("%lld%lld", &a[i].x, &a[i].y);
    sort(a + 1, a + n + 1, cmp);
    printf("%.4lf\n", sqrt(solve(1, n)));
    return 0;
}