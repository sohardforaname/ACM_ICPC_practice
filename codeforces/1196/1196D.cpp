#include <bits/stdc++.h>
using namespace std;
char ch[3]={'R','G','B'};
int dp[200005][3];
int main()
{
    int T,n,m;
    cin>>T;
    string str,str2[3];
    while(T--)
    {
        cin>>n>>m;
        cin>>str;
        dp[0][0]=(str[0]!=ch[0]);
        dp[0][1]=(str[0]!=ch[1]);
        dp[0][2]=(str[0]!=ch[2]);
        for(int i=1;i<n;++i)
        {
            dp[i][0]=dp[i-1][0]+(str[i]!=ch[(i)%3]);
            dp[i][1]=dp[i-1][1]+(str[i]!=ch[(i+1)%3]);
            dp[i][2]=dp[i-1][2]+(str[i]!=ch[(i+2)%3]);
        }
        /*for(int i=0;i<3;++i)
            for(int j=0;j<n;++j)
                cout<<dp[j][i]<<" ";
        cout<<endl;*/
        int res1=dp[m-1][0],res2=dp[m-1][1],res3=dp[m-1][2];
        for(int i=m;i<n;++i)
        {
            res1=min(res1,dp[i][0]-dp[i-m][0]);
            res2=min(res2,dp[i][1]-dp[i-m][1]);
            res3=min(res3,dp[i][2]-dp[i-m][2]);
        }
        int minn=min(res1,min(res2,res3));
        cout<<minn<<endl;
    }
    return 0;
}
