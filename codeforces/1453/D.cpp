#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5 + 5;
int ans[N];
int len;
void get(int l)
{
    l -= 2;
    ans[++len] = 1;
    for (int i = 1; i <= l; ++i)
        ans[++len] = 0;
}
void solve()
{
    ll n;
    scanf("%lld", &n);
    len = 0;
    if (n & 1)
        return void(printf("-1\n"));
    for (int i = 1; i < 64; ++i)
        if ((n >> i) & 1)
        {
            if (i == 1)
                get(i + 1);
            else
                get(i), get(2);
        }
    printf("%d\n", len);
    for (int i = 1; i <= len; ++i)
        printf("%d%c", ans[i], " \n"[i == len]);
}
int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
        solve();
    return 0;
}