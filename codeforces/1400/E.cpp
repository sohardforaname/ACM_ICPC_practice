#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 5e3 + 5;
int a[N];
int solve(int l, int r)
{
    if (l > r || (l == r && !a[l]))
        return 0;
    else if (l == r && a[l])
        return 1;
    int minn = 1e9 + 1, mid = 0;
    for (int i = l; i <= r; ++i)
        if (a[i] < minn)
            minn = a[i], mid = i;
    for (int i = l; i <= r; ++i)
        a[i] -= minn;
    return min(minn + solve(l, mid - 1) + solve(mid + 1, r), r - l + 1);
}
int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &a[i]);
    printf("%d\n", solve(1, n));
    return 0;
}