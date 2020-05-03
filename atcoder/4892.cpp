#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5 + 5, M = 3e3 + 5;
char s[N];
int cnt[M];
int main()
{
    int k = 1, sum = 0;
    scanf("%s", s);
    int len = strlen(s);
    for (int i = len - 1; ~i; --i)
    {
    }
    ll ans = 0;
    for (int i = 0; i < 2019; ++i)
    {
        if (!i)
            ans += cnt[i];
        else
            ans += cnt[i] * (cnt[i] - 1ll) / 2;
    }
    printf("%lld\n", ans);
    return 0;
}
