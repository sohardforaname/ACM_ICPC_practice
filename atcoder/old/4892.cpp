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
        sum = (sum + k * (s[i] - '0')) % 2019;
        ++cnt[sum];
        k = k * 10 % 2019;
    }
    ll ans = cnt[0];
    for (int i = 0; i < 2019; ++i)
        ans += cnt[i] * (cnt[i] - 1ll) / 2;
    printf("%lld\n", ans);
    return 0;
}
