#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int n;
        scanf("%d", &n);
        for (int i = 1; i <= n; ++i)
            printf("%d%c", 4 * n - 2 * (i - 1), " \n"[i == n]);
    }
    return 0;
}