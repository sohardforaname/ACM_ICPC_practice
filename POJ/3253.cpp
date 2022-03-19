#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <queue>
using namespace std;
typedef long long ll;
const int N = 1e5 + 5;
priority_queue<ll, vector<ll>, greater<ll>> q;
int main()
{
    int n, a;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &a), q.push(a);
    ll ans = 0;
    while (q.size() > 1)
    {
        ll tmp = q.top();
        q.pop();
        tmp += q.top();
        q.pop();
        ans += tmp;
        q.push(tmp);
    }
    printf("%lld\n", ans);
    return 0;
}