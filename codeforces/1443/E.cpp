#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
typedef long long ll;
ll fac[20];
int p[20], offset;
int getP(ll index)
{
    int tmp[20];
    for (int i = 1; i <= 15; ++i)
        tmp[i] = i;
    int j;
    for (index--, j = 1; j < 15; ++j)
    {
        p[j] = tmp[index / fac[15 - j] + 1];
        for (int i = index / fac[15 - j] + 1; i <= 15 - j; ++i)
            tmp[i] = tmp[i + 1];
    }
    p[15] = tmp[1];
}
int main()
{
    fac[0] = 1;
    for (int i = 1; i <= 15; ++i)
        fac[i] = fac[i - 1] * i;
    int n, m, cur = 1;
    scanf("%d%d", &n, &m);
    if (n > 15)
        offset = n - 15;
    while (m--)
    {
        int op, l, r;
        scanf("%d%d", &op, &l);
        if (op == 1)
        {
            scanf("%d", &r);
            if (r < n - 15)
                printf("%lld\n", (r - l + 1ll) * (l + r) / 2);
            else
            {
                ll ans = (n - 15ll - l) * (n - 16 + l) / 2;
            }
        }
    }
}