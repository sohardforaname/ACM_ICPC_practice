#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 5100;
int aa[maxn][maxn], mp[maxn][maxn], q[maxn];
inline int gcd(int a, int b)
{
    return !b ? a : gcd(b, a % b);
}
inline int lcm(int a, int b)
{
    return a * b / gcd(a, b);
}
int main()
{
    int n, m, a, b, k;
    scanf("%d%d%d", &n, &m, &k);
    a = k, b = k;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            aa[i][j] = lcm(i, j);
    for (int i = 1; i <= n; i++)
    {
        int l = 1, r = 0;
        for (int j = 1; j <= b; j++)
        {
            while (r && aa[i][q[r]] < aa[i][j])
                r--;
            q[++r] = j;
        }
        mp[i][1] = aa[i][q[l]];
        for (int j = 2; j + b - 1 <= m; j++)
        {
            if (q[l] == j - 1)
                l++;
            while (l <= r && aa[i][q[r]] < aa[i][j + b - 1])
                r--;
            q[++r] = j + b - 1;
            mp[i][j] = aa[i][q[l]];
        }
    }
    ll ans = 0;
    for (int j = 1; j <= m; j++)
    {
        int l = 1, r = 0;
        for (int i = 1; i <= a; i++)
        {
            while (r && mp[q[r]][j] < mp[i][j])
                r--;
            q[++r] = i;
        }
        (ans += mp[q[l]][j]);
        for (int i = 2; i + a - 1 <= n; i++)
        {
            if (q[l] == i - 1)
                l++;
            while (l <= r && mp[q[r]][j] < mp[i + a - 1][j])
                r--;
            q[++r] = i + a - 1;
            (ans += mp[q[l]][j]);
        }
    }
    printf("%lld\n", ans);
    return 0;
}