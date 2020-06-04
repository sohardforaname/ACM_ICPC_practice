#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
const int N = 1e5 + 5;
pair<int, int> p[N];
ll tpre[N];
bool cmp(const pair<int, int> &a, const pair<int, int> &b)
{
    return a.first * b.second < a.second * b.first;
}
int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        scanf("%d%d", &p[i].first, &p[i].second);
    sort(p + 1, p + n + 1, cmp);
    for (int i = 1; i <= n; ++i)
        tpre[i] = tpre[i - 1] + p[i].first;
    ll ans = 0;
    for (int i = 1; i <= n; ++i)
        ans += 2ll * tpre[i - 1] * p[i].second;
    printf("%lld\n", ans);
    return 0;
}