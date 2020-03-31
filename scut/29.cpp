#include <bits/stdc++.h>
using namespace std;
int dp[305][5];
int book[300][3];
#define maxx(a, b, c) (max(a, max(b, c)))
int main()
{
    int a[3];
    while (~scanf("%d%d%d", &a[0], &a[1], &a[2]))
    {
        memset(book, 0, sizeof(book));
        for (int i = 0; i < 3; ++i)
            for (int j = 0; j < a[i]; ++j)
                scanf("%d", &book[j][i]);
        memset(dp, 0, sizeof(dp));
        int t[3] = {a[0], a[1], a[2]};
        dp[1][0] = book[--t[0]][0];
        dp[1][1] = book[--t[1]][0];
        dp[1][2] = book[--t[2]][0];
        int sum = a[0] + a[1] + a[2];
        for (int i = 2; i <= sum; ++i)
        {
        }
    }
    return 0;
}
