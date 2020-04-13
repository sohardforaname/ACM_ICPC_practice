#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
const int M = 1e5 + 5;
int s[N], t[N];
int up[M], down[M];
int d[M];
int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d%d", &s[i], &t[i]);
        ++up[s[i]], ++down[t[i]];
        ++d[s[i]], --d[t[i]];
    }
    for (int i = 1; i < M; ++i)
    {
        up[i] += up[i - 1];
        down[i] += down[i - 1];
        d[i] += d[i - 1];
    }
    int ans1 = 0, ans2 = 0;
    for (int i = 1; i < M; ++i)
    {
        ans1 = max(ans1, up[t[i] - 1] - down[s[i]]);
        ans2 = max(ans2, d[s[i]]);
    }
    printf("%d %d\n", ans1, ans2);
    return 0;
}