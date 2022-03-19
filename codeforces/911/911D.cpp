#include <bits/stdc++.h>
using namespace std;
const int N = 1.5e3 + 5;
int a[N];
int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &a[i]);
    int cnt = 0;
    for (int i = 1; i <= n; ++i)
        for (int j = i + 1; j <= n; ++j)
            if (a[j] < a[i])
                ++cnt;
    int l, r, m;
    bool f = cnt % 2;
    scanf("%d", &m);
    for (int i = 1; i <= m; ++i)
    {
        scanf("%d%d", &l, &r);
        int tmp = (r - l + 1) * (r - l) / 2;
        f ^= tmp % 2;
        printf("%s", f ? "odd\n" : "even\n");
    }
    return 0;
}