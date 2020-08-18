#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int a[N];
int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int n;
        scanf("%d", &n);
        for (int i = 1; i <= n; ++i)
            scanf("%d", &a[i]);
        int x = 0;
        for (int i = 1; i <= n; ++i)
            x ^= a[i];
        if (x == 0)
        {
            printf("DRAW\n");
            continue;
        }
        for (int i = 30; ~i; --i)
        {
            int x = 0, y = 0;
            for (int j = 1; j <= n; ++j)
                ((a[j] >> i) & 1) ? ++x : ++y;
            if (x % 2)
            {
                if (x % 4 == 3 && y % 2 == 0)
                    printf("LOSE\n");
                else
                    printf("WIN\n");
                break;
            }
        }
    }
    return 0;
}