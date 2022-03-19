#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, a, b;
    scanf("%d%d%d", &n, &a, &b);
    int ans = 0;
    for (int i = 1; i < n; ++i)
        ans = max(ans, min(a / i, b / (n - i)));
    printf("%d\n", ans);
    return 0;
}