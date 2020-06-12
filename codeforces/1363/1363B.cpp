#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 5;
char s[N];
int pre[N];
void solve()
{
    scanf("%s", s + 1);
    int n = strlen(s + 1);
    for (int i = 1; i <= n; ++i)
        pre[i] = pre[i - 1] + s[i] - '0';
    int ans = N;
    for (int i = 0; i <= n; ++i)
    {
        ans = min(ans, i - pre[i] + pre[n] - pre[i]);
        ans = min(ans, pre[i] + n - i - (pre[n] - pre[i]));
    }
    printf("%d\n", ans);
}
int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
        solve();
    return 0;
}