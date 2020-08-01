#include <bits/stdc++.h>
using namespace std;
const int N = 2e2 + 5;
int cnt[N], sum[N];
void solve()
{
    int a;
    memset(cnt, 0, sizeof(cnt));
    for (int i = 0; i < 26; ++i)
    {
        scanf("%d", &a);
        ++cnt[a];
    }
    sum[0] = cnt[0];
    for (int i = 1; i <= 200; ++i)
        sum[i] = sum[i - 1] + cnt[i];
    int maxn = 0;
    for (int i = 2; i <= 100; ++i)
    {
        int len = 0;
        for (int j = i; j <= 100; j += i)
            len += (sum[j + i - 1] - sum[j - 1]) * j;
        maxn = max(maxn, len);
    }
    printf("%d\n", maxn);
}
int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
        solve();
    return 0;
}