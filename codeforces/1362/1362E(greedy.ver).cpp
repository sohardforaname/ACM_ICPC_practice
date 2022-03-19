#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
const int mod = 1e9 + 7;
typedef long long ll;
const ll INF = 1e6;
ll qpow(ll a, ll b, ll p)
{
    ll res = 1;
    while (b)
    {
        if (b & 1)
            res = res * a % p;
        a = a * a % p;
        b >>= 1;
    }
    return res;
}
int a[N];
int nowk, n;
ll dif, p, ans;
inline void cal(int x)
{
    ans = ans * qpow(p, nowk - x, mod) % mod;
    if (dif)
        for (int i = 1; i <= nowk - x; ++i)
        {
            dif = max(min(dif * p, INF), -INF);
            if (dif == 1e6 || dif == -1e6)
                break;
        }
    nowk = x;
}
inline void push(int x)
{
    cal(x);
    if (dif > 0)
        --ans, --dif;
    else
        ++ans, ++dif;
}
void solve()
{
    scanf("%d%lld", &n, &p);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &a[i]);
    sort(a + 1, a + n + 1, greater<int>());
    if (p == 1)
    {
        printf("%d\n", n % 2);
        return;
    }
    ans = dif = 0;
    nowk = N;
    for (int i = 1; i <= n; ++i)
        push(a[i]);
    cal(0);
    printf("%lld\n", (ans + mod) % mod);
}
int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
        solve();
    return 0;
}