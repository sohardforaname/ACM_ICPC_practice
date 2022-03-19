#include <bits/stdc++.h>
using namespace std;
int main()
{
    int tc;
    scanf("%d", &tc);
    while (tc--)
    {
        int n, a;
        scanf("%d", &n);
        bool f, fl = 1;
        scanf("%d", &a);
        f = a;
        for (int i = 2; i <= n; ++i)
        {
            scanf("%d", &a);
            if (fl)
            {
                if (!f && !a || f && a)
                    fl = 0;
                f = a;
            }
        }
        if (fl)
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}
