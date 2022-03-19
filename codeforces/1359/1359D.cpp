#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int n, a[N];
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &a[i]);
    int ans = 0;
    for (int i = 0; i < 31; ++i)
    {
        int sum = 0;
        for (int j = 1; j <= n; ++j)
        {
            if (a[j] > i)
            {
                sum = 0;
                continue;
            }
            sum += a[j];
            ans = max(ans, sum - i);
            if (sum < 0)
                sum = 0;
        }
    }
    printf("%d\n", ans);
    return 0;
}