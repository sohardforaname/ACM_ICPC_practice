#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5 + 5;
int a[N];
void solve()
{
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &a[i]);
    sort(a + 1, a + n + 1);
    if (n % 2)
    {
        printf("%d ", a[n / 2 + 1]);
        for (int i = 1; i <= n / 2; ++i)
        {
            printf("%d ", a[n / 2 + 1 + i]);
            printf("%d ", a[n / 2 + 1 - i]);
        }
        printf("\n");
    }
    else
    {
        printf("%d %d ", a[n / 2], a[n / 2 + 1]);
        for (int i = 1; i < n / 2; ++i)
        {
            printf("%d ", a[n / 2 - i]);
            printf("%d ", a[n / 2 + 1 + i]);
        }
        printf("\n");
    }
}
int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
        solve();
    return 0;
}