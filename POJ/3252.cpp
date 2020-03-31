#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
long long dp[35][100],a[35];
long long dfs(int pos,int sta,bool lead,int lim)
{
    if(pos==-1)
        return sta<=32;
    if(!lim&&!lead&&dp[pos][sta]!=-1)//有前导0，就会影响实际的0和1的判断
        return dp[pos][sta];
    int res=lim?a[pos]:1;
    long long ans=0;
    for(int i=0;i<=res;++i)
    {
        if(lead&&i==0)//前导0对判断0有影响，有前导0且本位是0时，证明还没有到真正的数位，一旦i是1，就会进入else
            ans+=dfs(pos-1,sta,lead,lim&&i==a[pos]);
        else//但是i为1，说明真正的数位开始了，后面都会认为没有前导0
            ans+=dfs(pos-1,sta+(i?1:-1),lead&&i==0,lim&&i==a[pos]);
    }
    if(!lim&&!lead)
        dp[pos][sta]=ans;
    return ans;
}
long long solve(int x)
{
    int pos=0;
    while(x)
    {
        a[pos++]=x%2;
        x>>=1;
    }
    return dfs(pos-1,32,true,true);
}
int main()
{
    memset(dp,-1,sizeof(dp));
    int l,r;
    cin>>l>>r;
    cout<<solve(r)-solve(l-1);
    return 0;
}
