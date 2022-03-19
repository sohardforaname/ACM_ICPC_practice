#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5 + 5;
ll sqr(ll a)
{
    return a * a;
}
ll cal(ll len, ll num)
{
    ll sz = len / num;
    ll ex = len - sz * num;
    return (num - ex) * sqr(sz) + ex * sqr(sz + 1);
}
priority_queue<pair<ll, pair<ll, ll>>> q;
int main()
{
    int n, k;
    scanf("%d%d", &n, &k);
    ll cost = 0;
    for (int i = 1; i <= n; ++i)
    {
        ll a;
        scanf("%lld", &a);
        cost += sqr(a);
        q.push({cal(a, 1) - cal(a, 2), {a, 2}});
    }
    for (int i = n; i < k; ++i)
    {
        auto cur = q.top();
        q.pop();
        ll a = cur.second.first;
        ll b = cur.second.second;
        cost -= cur.first;
        q.push({cal(a, b) - cal(a, b + 1), {a, b + 1}});
    }
    printf("%lld\n", cost);
    return 0;
}