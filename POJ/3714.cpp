#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>

using namespace std;
typedef long long ll;
const int N = 1e5 + 5;

struct point
{
    ll x, y;
    bool flag;
};
point p[N << 1];

const ll INF = 2e18;
int n;

bool cmp(const point &a, const point &b)
{
    return a.x == b.x ? a.y < b.y : a.x < b.x;
}
bool cmpy(const point &a, const point &b)
{
    return a.y < b.y;
}

ll sqr(ll x)
{
    return x * x;
}
ll dist(int i, int j)
{
    return p[i].flag ^ p[j].flag ? sqr(p[i].x - p[j].x) + sqr(p[i].y - p[j].y) : INF;
}

int b[N << 1];
ll solve(int l, int r)
{
    if (l >= r)
        return INF;
    int m = (l + r) >> 1;
    ll d = min(solve(l, m), solve(m + 1, r));
    int top = 0;
    for (int i = l; i <= r; ++i)
        if (sqr(p[i].x - p[m].x) <= d)
            b[++top] = i;
    sort(p + l, p + r + 1, cmpy);
    for (int i = 1; i < top; ++i)
        for (int j = i + 1; j <= top; ++j)
        {
            if (sqr(p[b[j]].y - p[b[i]].y) > d)
                break;
            d = min(d, dist(b[i], b[j]));
        }
    return d;
}

void solve()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        scanf("%lld%lld", &p[i].x, &p[i].y), p[i].flag = 0;
    for (int i = n + 1; i <= n * 2; ++i)
        scanf("%lld%lld", &p[i].x, &p[i].y), p[i].flag = 1;
    sort(p + 1, p + n * 2 + 1, cmp);
    printf("%.3f\n", sqrt(solve(1, 2 * n)));
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
        solve();
    return 0;
}