#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;
const int N = 5e5 + 5;
typedef long long ll;
typedef pair<int, int> pii;
const int M = 1e7 + 5;
bool isp[M];
int p[M], tot;
void init()
{
    memset(isp, 0x3f, sizeof(isp));
    for (int i = 2; i < M; ++i)
    {
        if (isp[i])
            p[++tot] = i;
        for (int j = 1; j <= tot && p[j] * i < M; ++j)
        {
            isp[p[j] * i] = 0;
            if (i % p[j] == 0)
                break;
        }
    }
}
int a[N];
pii ans[N];
int fac[N], top;
int n = 1000;
int gcd(int a, int b)
{
    return !b ? a : gcd(b, a % b);
}
pii get_fac(int x)
{
    for (int i = 2; i * i <= x; ++i)
        if (x % i == 0 && gcd(i, x / i) == 1)
            return {i, x / i};
    return {-1, -1};
}
unordered_map<int, pii> mp;
void solve()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &a[i]);
    for (int i = 1; i <= n; ++i)
    {
        if (isp[a[i]])
            ans[i] = {-1, -1};
        else
        {
            if (mp.find(a[i]) == mp.end())
            {
                get_fac(a[i]);
                if (top == 1)
                    ans[i] = {-1, -1};
                else
                    ans[i] = get_fac(a[i]);
                mp[a[i]] = ans[i];
            }
            else
                ans[i] = mp[a[i]];
        }
    }
    for (int i = 1; i <= n; ++i)
        printf("%d%c", ans[i].first, " \n"[i == n]);
    for (int i = 1; i <= n; ++i)
        printf("%d%c", ans[i].second, " \n"[i == n]);
}
int main()
{
    init();
    int T = 1;
    //scanf("%d", &T);
    while (T--)
        solve();
    return 0;
}