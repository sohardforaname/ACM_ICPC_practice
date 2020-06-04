#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;
const int N = 1e2 + 5;
int dp[N][N], p[N][N];
char s[N];
//#define tmax(a, b, c) (max((a), max((b), (c))))
int main()
{
    while (scanf("%s", s + 1) && s[1] != 'e')
    {
        memset(dp, 0, sizeof(dp));
        int n = strlen(s + 1);
        for (int len = 2; len <= n; ++len)
            for (int i = 1; i <= n; ++i)
            {
                int j = i + len - 1;
                if (j > n)
                    continue;
                if ((s[i] == '(' && s[j] == ')') || (s[i] == '[' && s[j] == ']'))
                    dp[i][j] = dp[i + 1][j - 1] + 2;
                for (int k = i + 1; k < j; ++k)
                    dp[i][j] = max(dp[i][j], dp[i][k] + dp[k][j]);
            }
        printf("%d\n", dp[1][n]);
    }
    return 0;
}