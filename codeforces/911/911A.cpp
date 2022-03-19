#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int a[N];
int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &a[i]);
    int minn = *min_element(a + 1, a + n + 1);
    int pre = 0, ans = n + 1;
    for (int i = 1; i <= n; ++i)
        if (a[i] == minn)
        {
            if (!pre)
                pre = i;
            else
            {
                ans = min(ans, i - pre);
                pre = i;
            }
        }
    printf("%d\n", ans);
    return 0;
}