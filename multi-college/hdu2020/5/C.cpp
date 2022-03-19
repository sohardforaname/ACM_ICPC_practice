#include <bits/stdc++.h>
using namespace std;
const int N = 2.5e5 + 5;
int a[N], a1[N];
int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        int n, k;
        scanf("%d%d", &n, &k);
        for (int i = 1; i <= 2 * n * (1 << k); ++i)
            scanf("%d", &a[i]);
        int tmp = 2 * n * (1 << k);
        int tot = tmp;
        while (tmp > 1)
        {
            int top = 0;
            int l = tot / 2, r = tot / 2 + 1;
            while (l >= 1 && r <= tot)
            {
                for (int j = 1; j <= tot / tmp; ++j)
                    a1[++top] = a[l--];
                for (int j = 1; j <= tot / tmp; ++j)
                    a1[++top] = a[r++];
            }
            memcpy(a, a1, sizeof(int) * tot);
            tmp /= 2;
        }
        for (int i = 1; i <= tot; ++i)
            printf("%d%c", a[i], " \n"[i == tot]);
    }
    return 0;
}