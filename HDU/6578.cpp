#include <bits/stdc++.h>
using namespace std;
int dp[2][105][105][105];//i,j,k,l表示到了第i位，0，1，2，3的位置（分别用i，j，k，l表示）
vector<pair<int,int> >limvec[105];
const long long mod=998244353;
int add(int x,int y)
{
    return int((long long)(x+y)%mod);
}
bool check(int a,int b,int c,int d)//保证a>=b>=c>=d
{
    for(auto i:limvec[a])
    {
        int l=i.first,k=i.second;
        if((l<=a)+(l<=b)+(l<=c)+(l<=d)!=k)
            return false;
    }
    return true;
}
int main()
{
    int T,n,m,a,b,c;
    cin>>T;
    while(T--)
    {
        cin>>n>>m;
        for(int i=1;i<=n;++i)
            limvec[i].clear();
        for(int i=0;i<m;++i)
        {
            cin>>a>>b>>c;
            limvec[b].push_back(make_pair(a,c));
        }
        dp[0][0][0][0]=1;//0的时候没开始放,也是一种放法23333
        int ans=0,cur=0;
        for(int i=0;i<=n;++i)
        {
            for(int j=0;j<=i;++j)
                for(int k=0;k<=j;++k)
                    for(int l=0;l<=k;++l)
                        dp[!cur][j][k][l]=0;//清空下一层的状态
            for(int j=0;!j||j<i;++j)//0的时候没有放，当然可以是一种状态，此处无视其他为0
                for(int k=0;!k||k<j;++k)
                    for(int l=0;!l||l<k;++l)
                    {
                        if(!check(i,j,k,l))
                        {
                            dp[cur][j][k][l]=0;
                            continue;
                        }
                        if(!dp[cur][j][k][l])//这一层凉了，下面都不用放了
                            continue;
                        if(i==n)
                        {
                            ans=add(ans,dp[cur][j][k][l]);
                            dp[cur][j][k][l]=0;//完成任务
                            continue;
                        }
                        dp[!cur][j][k][l]=add(dp[!cur][j][k][l],dp[cur][j][k][l]);
                        dp[!cur][i][k][l]=add(dp[!cur][i][k][l],dp[cur][j][k][l]);
                        dp[!cur][i][j][l]=add(dp[!cur][i][j][l],dp[cur][j][k][l]);
                        dp[!cur][i][j][k]=add(dp[!cur][i][j][k],dp[cur][j][k][l]);
                    }
            cur=!cur;
        }
        cout<<ans<<endl;
    }
    return 0;
}
