#include <bits/stdc++.h>
#define maxx(a,b,c) (max(a,max(b,c)))
using namespace std;
int num[100005][2];
long long dp[100005][3];
int main()
{
    freopen("D:\\in.txt","r",stdin);
    int n;
    cin>>n;
    for(int i=0;i<n;++i)
        cin>>num[i][0];
    for(int i=0;i<n;++i)
        cin>>num[i][1];
    dp[0][0]=0;
    dp[0][1]=num[0][0];
    dp[0][2]=num[0][1];
    for(int i=1;i<n;++i)
    {
        dp[i][0]=maxx(dp[i-1][0],dp[i-1][1],dp[i-1][2]);
        dp[i][1]=max(dp[i-1][0],dp[i-1][2])+num[i][0];
        dp[i][2]=max(dp[i-1][0],dp[i-1][1])+num[i][1];
    }
    cout<<maxx(dp[n-1][0],dp[n-1][1],dp[n-1][2])<<endl;
    return 0;
}
