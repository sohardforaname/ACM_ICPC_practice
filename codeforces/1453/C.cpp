#include <bits/stdc++.h>
using namespace std;
const int N = 2e3 + 5;
char s[N][N];
int minl[N], maxr[N], minu[N], maxd[N];
int ans[N];
void solve()
{
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        scanf("%s", &s[i][1]);
    for (int i = 0; i < 10; ++i)
        minl[i] = minu[i] = 0x3f3f3f3f, maxr[i] = maxd[i] = 0, ans[i] = 0;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
        {
            int t = s[i][j] - '0';
            minl[t] = min(minl[t], j), maxr[t] = max(maxr[t], j);
            minu[t] = min(minu[t], i), maxd[t] = max(maxd[t], i);
        }
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
        {
            int t = s[i][j] - '0';
            ans[t] = max({ans[t],
                          max(j - minl[t], maxr[t] - j) * max(n - i, i - 1),
                          max(i - minu[t], maxd[t] - i) * max(n - j, j - 1)});
        }
    for (int i = 0; i < 10; ++i)
        printf("%d%c", ans[i], " \n"[i == 9]);
}
int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
        solve();
    return 0;
}