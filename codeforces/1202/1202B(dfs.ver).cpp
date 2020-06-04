#include <bits/stdc++.h>
using namespace std;
int dp[15][15][15], res[15][15];
char str[2000005];
int x, y;
void dfs(int div, bool mode, int cur)
{
    if (!mode)
    {
        cur = (cur + x) % 10;
        if (dp[x][y][cur] != -1)
            if (div >= dp[x][y][cur])
                return;
        dp[x][y][cur] = div;
        dfs(div + 1, 0, cur);
        dfs(div + 1, 1, cur);
    }
    else
    {
        cur = (cur + y) % 10;
        if (dp[x][y][cur] != -1)
            if (div >= dp[x][y][cur])
                return;
        dp[x][y][cur] = div;
        dfs(div + 1, 0, cur);
        dfs(div + 1, 1, cur);
    }
}
void init()
{
    memset(dp, -1, sizeof(dp));
    for (int i = 0; i < 10; ++i)
        for (int j = 0; j < 10; ++j)
        {
            x = i, y = j;
            dfs(0, 0, 0);
            dfs(0, 1, 0);
        }
}
int cal(int x, int y, int len)
{
    if (len == 1)
        return 0;
    int ans = 0;
    for (int i = 1; i < len; ++i)
    {
        int tmp;
        int dis = str[i] - str[i - 1];
        while (dis < 0)
            dis += 10;
        tmp = dp[x][y][dis];
        if (tmp == -1)
            return -1;
        else
            ans += tmp;
    }
    return ans;
}
int main()
{
    init();
    scanf("%s", str);
    int len = strlen(str);
    /*for(int i=0;i<10;++i)
        for(int j=0;j<10;++j)
            for(int k=0;k<10;++k)
                printf("%d,%d:%d%c",i,j,dp[i][j][k],(k==9?'\n':' '));*/
    for (int i = 0; i < 10; ++i)
        for (int j = 0; j < 10; ++j)
            /*res[j][i]=*/res[i][j] = cal(i, j, len);
    for (int i = 0; i < 10; ++i)
        for (int j = 0; j < 10; ++j)
            printf("%d%c", res[i][j], (j == 9 ? '\n' : ' '));
    return 0;
}
