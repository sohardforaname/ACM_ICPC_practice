#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5 + 5;
int r[N], c[N];
void solve()
{
    int n, q;
    bool f = 0;
    scanf("%d%d", &n, &q);
    for (int i = 1; i <= q; ++i)
    {
        int a, x, y;
        scanf("%d", &a);
        if (a == 3)
        {
            swap(c, r);
            f ^= 1;
        }
        else
        {
            scanf("%d%d", &x, &y);
            if (a == 1)
            {
                if (x > y)
                    swap(x, y);
                int orx = r[x], ory = r[y];
                r[x] = y - x + ory;
                r[y] = x - y + orx;
            }
            else if (a == 2)
            {
                if (x > y)
                    swap(x, y);
                int ocx = c[x], ocy = c[y];
                c[x] = y - x + ocy;
                c[y] = x - y + ocx;
            }
            else if (a == 4)
            {
                if (!f)
                    printf("%lld\n", n * (x - 1ll + r[x]) + y - 1ll + c[y]);
                else
                    printf("%lld\n", n * (y - 1ll + c[y]) + x - 1ll + r[x]);
            }
        }
    }
}
int main()
{
    int T = 1;
    //scanf("%d", &T);
    while (T--)
        solve();
    return 0;
}