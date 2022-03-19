#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e2 + 5;
ll a[N], d[N];
void add(ll x)
{
    for (int i = 62; ~i; --i)
        if (x & (1ll << i))
        {
            if (d[i])
                x ^= d[i];
            else
            {
                d[i] = x;
                break;
            }
        }
}
char s[N];
int main()
{
    int m, n;
    scanf("%d%d", &m, &n);
    for (int i = 1; i <= n; ++i)
    {
        scanf("%s", s);
        for (int j = 0; j < m; ++j)
            a[i] += (1ll << (m - 1ll - j)) * (s[j] == 'O');
        add(a[i]);
    }
    int cnt = 0;
    for (int i = 0; i < 63; ++i)
        if (d[i])
            ++cnt;
    printf("%lld", (1ll << cnt) % 2008);
    return 0;
}