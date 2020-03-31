#include <bits/stdc++.h>
using namespace std;
int dp[15][15],len;
char str[2000005];
const int inf=0x3f3f3f3f;
int solve(int x,int y)
{
    memset(dp,inf,sizeof(dp));
    for(int i=0;i<10;++i)
        dp[i][(i+x)%10]=dp[i][(i+y)%10]=1;
    for(int k=0;k<10;++k)
        for(int i=0;i<10;++i)
            for(int j=0;j<10;++j)
                dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]);
    int ans=0;
    for(int i=1;i<len;++i)
    {
        if(dp[str[i-1]-'0'][str[i]-'0']>=inf)
            return -1;
        ans+=dp[str[i-1]-'0'][str[i]-'0']-1;
    }
    return ans;
}
int main()
{
    scanf("%s",str);
    len=strlen(str);
    for(int i=0;i<10;++i)
        for(int j=0;j<10;++j)
            printf("%d%c",solve(i,j),(j==9?'\n':' '));
    return 0;
}
