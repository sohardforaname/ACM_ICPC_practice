#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5 + 5;
int a[N];
bool f[N];
void solve()
{
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &a[i]);
    memset(f, 0, sizeof(f[0]) * (n + 1));
    for (int i = 2; i <= n; ++i)
        if (a[i] == a[i - 1] + 1)
            f[i] = 1;
    int pos = n, pre = n;
    int cnt = 1;
    while (pos)
    {
        if (f[pos])
        {
            --pos;
            continue;
        }
        else
        {
            for (int i = pos; i <= pre; ++i)
            {
                if (cnt != a[i])
                {
                    printf("No\n");
                    return;
                }
                ++cnt;
            }
            pre = pos - 1;
            --pos;
        }
    }
    printf("Yes\n");
}
int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
        solve();
    return 0;
}